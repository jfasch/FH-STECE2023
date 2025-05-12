#include "door.h"
#include "light-barrier.h"
#include <assert.h>



void Door::Door_check()
{
    switch (this->_state) {
        case DOOR_INIT: {
            // figure out the state we are in: where is the door?
            LightBarrier::LightBarrierState closed_barrier_state = this->_closed->LightBarrier_get_state();
            LightBarrier::LightBarrierState opened_barrier_state  = this->_open->LightBarrier_get_state() ;

            if (closed_barrier_state == LightBarrier::LIGHTBARRIER_BEAM_SOLID && opened_barrier_state == LightBarrier::LIGHTBARRIER_BEAM_SOLID)
                _state = DOOR_ERROR_MIDDLE_POSITION;   // FIXME: recover from that
            else if (closed_barrier_state == LightBarrier::LIGHTBARRIER_BEAM_BROKEN && opened_barrier_state == LightBarrier::LIGHTBARRIER_BEAM_BROKEN)
                _state = DOOR_ERROR_SOMETHING_BADLY_WRONG;
            else if (closed_barrier_state == LightBarrier::LIGHTBARRIER_BEAM_BROKEN && opened_barrier_state == LightBarrier::LIGHTBARRIER_BEAM_SOLID)
                _state = DOOR_CLOSED;
            else if (closed_barrier_state == LightBarrier::LIGHTBARRIER_BEAM_SOLID && opened_barrier_state == LightBarrier::LIGHTBARRIER_BEAM_BROKEN)
                _state = DOOR_OPENED;
            else 
                assert(!"well, two bits make four values");
            break;
        }
        case DOOR_CLOSED: {
            // "open" requested (button press). drive motor, and
            // switch state to "opening"
            if (this->_do_open->PushButton_get_state()== PushButton::PUSHBUTTON_PRESSED) {
                this->_motor->forward();
                this->_state = DOOR_OPENING;
            }

            // FIXME: what if user pressed "do_close" at the same
            // time?

            // FIXME: invariants
            break;
        }
        case DOOR_OPENING: {
            // see if we already reached the end position. if so, stop
            // motor and adjust door state.
           LightBarrier::LightBarrierState opened_barrier_state = this->_open->LightBarrier_get_state();
            if (opened_barrier_state ==LightBarrier::LIGHTBARRIER_BEAM_BROKEN) {
                this->_motor->stop();
                _state = DOOR_OPENED;
            }

            // FIXME: invariants
            break;
        }
        case DOOR_OPENED: {
            assert(false);
            break;
        }
        case DOOR_ERROR_MIDDLE_POSITION: {
            assert(false);
            break;
        }
        case DOOR_ERROR_SOMETHING_BADLY_WRONG: {
            assert(false);
            break;
        }
    }
}
