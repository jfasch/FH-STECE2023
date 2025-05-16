#include "door.h"

#include <assert.h>


Door::Door(Motor* motor, PushButton* do_close, PushButton* do_open, 
           LightBarrier* closed_position, LightBarrier* opened_position)
{
    // assume that the motor is idle when the software boots. FIXME:
    // is that assumption safe?
    // FIX: stop the motor on initialization
    motor->stop();
    assert(motor->get_direction() == MotorDirection::IDLE);

    _motor = motor;
    _do_close = do_close;
    _do_open = do_open;
    _closed_position = closed_position;
    _opened_position = opened_position;

    _state = DoorState::INIT;
}

void Door::check()
{
    switch (_state) {
        case DoorState::INIT: {
            // figure out the state we are in: where is the door?
            LightBarrierState closed_barrier_state = _closed_position->get_state();
            LightBarrierState opened_barrier_state = _opened_position->get_state();

            if (closed_barrier_state == LightBarrierState::BEAM_SOLID && opened_barrier_state == LightBarrierState::BEAM_SOLID)
                _state = DoorState::ERROR_MIDDLE_POSITION;   // FIXME: recover from that
            else if (closed_barrier_state == LightBarrierState::BEAM_BROKEN && opened_barrier_state == LightBarrierState::BEAM_BROKEN)
                _state = DoorState::ERROR_SOMETHING_BADLY_WRONG;
            else if (closed_barrier_state == LightBarrierState::BEAM_BROKEN && opened_barrier_state == LightBarrierState::BEAM_SOLID)
                _state = DoorState::CLOSED;
            else if (closed_barrier_state == LightBarrierState::BEAM_SOLID && opened_barrier_state == LightBarrierState::BEAM_BROKEN)
                _state = DoorState::OPENED;
            else 
                assert(!"well, two bits make four values"); // <-- if we are here, we have a problem
            break;
        }
        case DoorState::CLOSED: {
            // "open" requested (button press). drive motor, and
            // switch state to "opening"
            if (_do_open->get_state() == PushButtonState::PRESSED) {
                _motor->forward();
                _state = DoorState::OPENING;
            }

            // FIXME: what if user pressed "do_close" at the same
            // time?
            // -> the door is already closed. user problably pressed the wrong button. just ignore him.

            // FIXME: invariants
            break;
        }
        case DoorState::OPENING: {
            // see if we already reached the end position. if so, stop
            // motor and adjust door state.
            LightBarrierState opened_barrier_state = _opened_position->get_state();
            if (opened_barrier_state == LightBarrierState::BEAM_BROKEN) {
                _motor->stop();
                _state = DoorState::OPENED;
            }

            // FIXME: invariants
            break;
        }
        case DoorState::OPENED: {
            assert(false);
            break;
        }
        case DoorState::ERROR_MIDDLE_POSITION: {
            assert(false);
            break;
        }
        case DoorState::ERROR_SOMETHING_BADLY_WRONG: {
            assert(false);
            break;
        }
    }
}
