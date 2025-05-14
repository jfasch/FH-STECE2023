#include "door.h"

#include <assert.h>


Door::Door(Motor* motor, PushButton* do_close, PushButton* do_open, 
     LightBarrier* closed_position, LightBarrier* opened_position)
{
    // assume that the motor is idle when the software boots. FIXME:
    // is that assumption safe?
    assert(motor->getDirection() == Motor::Direction::IDLE);

    _motor = motor;
    _do_close = do_close;
    _do_open = do_open;
    _closed_position = closed_position;
    _opened_position = opened_position;

    _state = Door::State::INIT;
}

void Door::check()
{
    switch (_state) {
        case Door::State::INIT: {
            // figure out the state we are in: where is the door?
            LightBarrier::State closed_barrier_state = _closed_position->getState();
            LightBarrier::State opened_barrier_state = _opened_position->getState();
            
            if (closed_barrier_state == LightBarrier::State::BeamSolid && opened_barrier_state == LightBarrier::State::BeamSolid)
                _state = Door::State::ERROR_MIDDLE_POSITION;
            else if (closed_barrier_state == LightBarrier::State::BeamBroken && opened_barrier_state == LightBarrier::State::BeamBroken)
                _state = Door::State::ERROR_SOMETHING_BADLY_WRONG;
            else if (closed_barrier_state == LightBarrier::State::BeamBroken && opened_barrier_state == LightBarrier::State::BeamSolid)
                _state = Door::State::CLOSED;
            else if (closed_barrier_state == LightBarrier::State::BeamSolid && opened_barrier_state == LightBarrier::State::BeamBroken)
                _state = Door::State::OPENED;
            else 
                assert(!"well, two bits make four values");
            break;
        }
        case Door::State::CLOSED: {
            // "open" requested (button press). drive motor, and
            // switch state to "opening"
            if (_do_open->getState() == PushButton::State::PUSHBUTTON_PRESSED) {
                _motor->forward();
                _state = Door::State::OPENING;
            }

            // FIXME: what if user pressed "do_close" at the same
            // time?

            // FIXME: invariants
            break;
        }
        case Door::State::OPENING: {
            // see if we already reached the end position. if so, stop
            // motor and adjust door state.
            LightBarrier::State opened_barrier_state = _opened_position->getState();
            if (opened_barrier_state == LightBarrier::State::BeamBroken) {
                _motor->stop();
                _state = Door::State::OPENED;
            }

            // FIXME: invariants
            break;
        }
        case Door::State::OPENED: {
            assert(false);
            break;
        }
        case Door::State::ERROR_MIDDLE_POSITION : {
            assert(false);
            break;
        }
        case Door::State::ERROR_SOMETHING_BADLY_WRONG : {
            assert(false);
            break;
        }
    }
}
