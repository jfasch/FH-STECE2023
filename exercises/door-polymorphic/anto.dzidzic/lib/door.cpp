#include "door.h"

#include <assert.h>


Door::Door(IMotor* motor, 
           IPushButton* do_close, IPushButton* do_open, 
           ILightBarrier* closed_position, ILightBarrier* opened_position)
{
    // assume that the motor is idle when the software boots. FIXME:
    // is that assumption safe?
    //assert(motor->get_direction() == Motor::Direction::IDLE);

    _motor = motor;
    _do_close = do_close;
    _do_open = do_open;
    _closed_position = closed_position;
    _opened_position = opened_position;

    _state = State::INIT;
}

void Door::check()
{
    switch (_state) {
        case State::INIT: {
            // figure out the state we are in: where is the door?
            ILightBarrier::State closed_barrier_state = _closed_position->get_state();
            ILightBarrier::State opened_barrier_state = _opened_position->get_state();

            if (closed_barrier_state == ILightBarrier::State::BEAM_SOLID && opened_barrier_state == ILightBarrier::State::BEAM_SOLID)
                _state = State::ERROR_MIDDLE_POSITION;   // FIXME: recover from that
            else if (closed_barrier_state == ILightBarrier::State::BEAM_BROKEN && opened_barrier_state == ILightBarrier::State::BEAM_BROKEN)
                _state = State::ERROR_SOMETHING_BADLY_WRONG;
            else if (closed_barrier_state == ILightBarrier::State::BEAM_BROKEN && opened_barrier_state == ILightBarrier::State::BEAM_SOLID)
                _state = State::CLOSED;
            else if (closed_barrier_state == ILightBarrier::State::BEAM_SOLID && opened_barrier_state == ILightBarrier::State::BEAM_BROKEN)
                _state = State::OPENED;
            else 
                assert(!"well, two bits make four values");
            break;
        }
        case State::CLOSED: {
            // "open" requested (button press). drive motor, and
            // switch state to "opening"
            if (_do_open->get_state() == IPushButton::State::PRESSED) {
                _motor->forward();
                _state = State::OPENING;
            }

            // FIXME: what if user pressed "do_close" at the same
            // time?

            // FIXME: invariants
            break;
        }
        case State::OPENING: {
            // see if we already reached the end position. if so, stop
            // motor and adjust door state.
            ILightBarrier::State opened_barrier_state = _opened_position->get_state();
            if (opened_barrier_state == ILightBarrier::State::BEAM_BROKEN) {
                _motor->stop();
                _state = State::OPENED;
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
