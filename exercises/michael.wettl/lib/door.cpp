#include "door.h"

#include <assert.h>


Door::Door(Motor* motor, PushButton* do_close, PushButton* do_open, 
           LightBarrier* closed_position, LightBarrier* opened_position)
        {
            _motor = motor;
            _do_close = do_close;
            _do_open = do_open;
            _closed_position = closed_position;
            _opened_position = opened_position;

            _state = DoorState::DOOR_INIT;
        }
void Door::Door_check()
{
    switch (_state) {      
        case DoorState::DOOR_INIT: {
            // figure out the state we are in: where is the door?
            LightBarrierState closed_barrier_state = _closed_position->get_state();
            LightBarrierState opened_barrier_state = _opened_position->get_state();

            if (closed_barrier_state == LightBarrierState::LIGHTBARRIER_BEAM_SOLID && 
                opened_barrier_state == LightBarrierState::LIGHTBARRIER_BEAM_BROKEN)
                _state = DoorState::DOOR_ERROR_MIDDLE_POSITION; // FIXME: recover from that
            else if (closed_barrier_state == LightBarrierState::LIGHTBARRIER_BEAM_BROKEN && 
                opened_barrier_state == LightBarrierState::LIGHTBARRIER_BEAM_BROKEN)
                _state = DoorState::DOOR_ERROR_SOMETHING_BADLY_WRONG;
            else if (closed_barrier_state == LightBarrierState::LIGHTBARRIER_BEAM_BROKEN && 
                opened_barrier_state == LightBarrierState::LIGHTBARRIER_BEAM_SOLID)
                _state = DoorState::DOOR_CLOSED;
            else if (closed_barrier_state == LightBarrierState::LIGHTBARRIER_BEAM_SOLID && 
                opened_barrier_state == LightBarrierState::LIGHTBARRIER_BEAM_BROKEN)
                _state = DoorState::DOOR_OPENED;
            else 
                assert(!"well, two bits make four values");
            break;
        }
        case DoorState::DOOR_CLOSED: {
            // "open" requested (button press). drive motor, and
            // switch state to "opening"
            if (_do_open->get_state() == PushButtonState::PUSHBUTTON_PRESSED) {
                _motor->Motor_forward();
                _state = DoorState::DOOR_OPENING;
            }

            // FIXME: what if user pressed "do_close" at the same
            // time?
            if (_do_open->get_state() == PushButtonState::PUSHBUTTON_PRESSED &&
                _do_close->get_state() == PushButtonState::PUSHBUTTON_PRESSED)  // if both buttons are pressed at the same time
            {
                _motor->Motor_stop();                                       // stop the motor
                _state = DoorState::DOOR_ERROR_SOMETHING_BADLY_WRONG;      // set the state to badly mode is a bit dramatic you can set it to do nothing
            }
            // FIXME: invariants
            break;
        }
        case DoorState::DOOR_OPENING: {
            // see if we already reached the end position. if so, stop
            // motor and adjust door state.
            LightBarrierState opened_barrier_state = _opened_position->get_state();
            if (opened_barrier_state == LightBarrierState::LIGHTBARRIER_BEAM_BROKEN) {
                _motor->Motor_stop();
                _state = DoorState::DOOR_OPENED;
            }

            // FIXME: invariants
            break;
        }
        case DoorState::DOOR_OPENED: {
            assert(false);
            break;
        }
        case DoorState::DOOR_ERROR_MIDDLE_POSITION: {
            assert(false);
            break;
        }
        case DoorState::DOOR_ERROR_SOMETHING_BADLY_WRONG: {
            assert(false);
            break;
        }
    }
}
