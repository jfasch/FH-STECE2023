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

    _state = DOOR_INIT;

    // assume that the motor is idle when the software boots. FIXME: is that assumption safe?
    _motor->stop(); //stop motor during boot if not yet in IDLE

    assert(_motor->get_direction() == MOTOR_IDLE);
}

DoorState Door::get_state() 
{
    return _state;
}

void Door::check()
{
    switch (_state) {
        case DOOR_INIT: {
            // figure out the state we are in: where is the door?
            LightBarrierState closed_barrier_state = _closed_position->get_state();
            LightBarrierState opened_barrier_state = _opened_position->get_state();

            if (closed_barrier_state == LIGHTBARRIER_BEAM_SOLID && opened_barrier_state == LIGHTBARRIER_BEAM_SOLID)
                _state = DOOR_ERROR_MIDDLE_POSITION;   
            else if (closed_barrier_state == LIGHTBARRIER_BEAM_BROKEN && opened_barrier_state == LIGHTBARRIER_BEAM_BROKEN)
                _state = DOOR_ERROR_SOMETHING_BADLY_WRONG;
            else if (closed_barrier_state == LIGHTBARRIER_BEAM_BROKEN && opened_barrier_state == LIGHTBARRIER_BEAM_SOLID)
                _state = DOOR_CLOSED;
            else if (closed_barrier_state == LIGHTBARRIER_BEAM_SOLID && opened_barrier_state == LIGHTBARRIER_BEAM_BROKEN)
                _state = DOOR_OPENED;
            else 
                assert(!"well, two bits make four values");
            break;
        }
        case DOOR_CLOSED: {
            // "open" requested (button press). drive motor, and
            // switch state to "opening"
            if (_do_open->get_state() == PUSHBUTTON_PRESSED) {
                _motor->forward();
                _state = DOOR_OPENING;
            }
            else if(_do_close->get_state() == PUSHBUTTON_PRESSED) {
                //ignore input
            }
            break;
        }
        case DOOR_OPENING: {
            // see if we already reached the end position. if so, stop
            // motor and adjust door state.
            LightBarrierState opened_barrier_state = _opened_position->get_state();
            if (opened_barrier_state == LIGHTBARRIER_BEAM_BROKEN) {
                _motor->stop();
                _state = DOOR_OPENED;
            }
            else if(_do_open->get_state() == PUSHBUTTON_PRESSED) {
                //do nothing
            }
            else if(_do_close->get_state() == PUSHBUTTON_PRESSED) {
                _motor->backward();
                _state = DOOR_CLOSING;
            }
            
            break;
        }
        case DOOR_OPENED: {
            
            if (_do_close->get_state() == PUSHBUTTON_PRESSED) {
                _motor->backward();
                _state = DOOR_CLOSING;
            }
            else if(_do_open->get_state() == PUSHBUTTON_PRESSED) {
                //ignore input
            }
            break;
        }
        case DOOR_CLOSING: {
            LightBarrierState closed_barrier_state = _closed_position->get_state();
            if (closed_barrier_state == LIGHTBARRIER_BEAM_BROKEN) {
                _motor->stop();
                _state = DOOR_CLOSED;
            }
            else if(_do_close->get_state() == PUSHBUTTON_PRESSED) {
                //do nothing
            }
            else if(_do_open->get_state() == PUSHBUTTON_PRESSED){
                _motor->forward();
                _state = DOOR_OPENING;
            }

            break;
        }
        case DOOR_ERROR_MIDDLE_POSITION: {
            if(_do_open->get_state() == PUSHBUTTON_PRESSED && _do_close->get_state() == PUSHBUTTON_RELEASED){
                _motor->forward();
                _state = DOOR_OPENING;
            }
            else if(_do_open->get_state() == PUSHBUTTON_RELEASED && _do_close->get_state() == PUSHBUTTON_PRESSED){
                _motor->backward();
                _state = DOOR_CLOSING;
            }
            else if(_do_open->get_state() == PUSHBUTTON_PRESSED && _do_close->get_state() == PUSHBUTTON_PRESSED) {
                //both buttons pressed => stay in this case
            }
            break;
        }
        case DOOR_ERROR_SOMETHING_BADLY_WRONG: {
            assert(!"well, really bad");
            break;
        }
    }
}
