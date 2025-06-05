#include "door.h"

#include <assert.h>

Door::Door(Motor* motor, 
           PushButton* do_close, PushButton* do_open, 
           LightBarrier* closed_position, LightBarrier* opened_position)
{
    // assume that the motor is idle when the software boots. FIXME:
    // is that assumption safe?
    assert(motor->get_direction() == Motor::Direction::IDLE);

    motor_ = motor;
    do_close_ = do_close;
    do_open_ = do_open;
    closed_position_ = closed_position;
    opened_position_ = opened_position;

    state_ = State::INIT;
}

void Door::check()
{
    switch (state_) {
        case State::INIT: {
            // figure out the state we are in: where is the door?
            LightBarrier::State closed_barrier_state = closed_position_->get_state();
            LightBarrier::State opened_barrier_state = opened_position_->get_state();

            if (closed_barrier_state == LightBarrier::State::BEAM_SOLID && opened_barrier_state == LightBarrier::State::BEAM_SOLID)
                state_ = State::ERROR_MIDDLE_POSITION;   // FIXME: recover from that
            else if (closed_barrier_state == LightBarrier::State::BEAM_BROKEN && opened_barrier_state == LightBarrier::State::BEAM_BROKEN)
                state_ = State::ERROR_SOMETHING_BADLY_WRONG;
            else if (closed_barrier_state == LightBarrier::State::BEAM_BROKEN && opened_barrier_state == LightBarrier::State::BEAM_SOLID)
                state_ = State::CLOSED;
            else if (closed_barrier_state == LightBarrier::State::BEAM_SOLID && opened_barrier_state == LightBarrier::State::BEAM_BROKEN)
                state_ = State::OPENED;
            else 
                assert(!"well, two bits make four values");
            break;
        }
        case State::CLOSED: {
            // "open" requested (button press). drive motor, and
            // switch state to "opening"
            if (do_open_->get_state() == PushButton::State::PRESSED) {
                motor_->forward();
                state_ = State::OPENING;
            }

            // FIXME: what if user pressed "do_close" at the same
            // time?

            // FIXME: invariants
            break;
        }
        case State::OPENING: {
            // see if we already reached the end position. if so, stop
            // motor and adjust door state.
            LightBarrier::State opened_barrier_state = opened_position_->get_state();
            if (opened_barrier_state == LightBarrier::State::BEAM_BROKEN) {
                motor_->stop();
                state_ = State::OPENED;
            }

            // FIXME: invariants
            break;
        }
        case State::OPENED: {
            assert(false);
            break;
        }
        case State::ERROR_MIDDLE_POSITION: {
            assert(false);
            break;
        }
        case State::ERROR_SOMETHING_BADLY_WRONG: {
            assert(false);
            break;
        }
    }
}

Door::State Door::get_state() const
{
    return state_;
}
