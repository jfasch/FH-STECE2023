#include "door.h"

#include <assert.h>



void Door::check()
{
    switch (state) {
        case DoorState::INIT: {

        
            // figure out the state we are in: where is the door?
            auto closed_state = closed_position->get_state();
            auto opened_state = opened_position->get_state();

            if (closed_state == LightBarrierState::BEAM_SOLID && opened_state == LightBarrierState::BEAM_SOLID)
                state = DoorState::ERROR_MIDDLE_POSITION;  // FIXed?: recover from that // yes works
            else if (closed_state == LightBarrierState::BEAM_BROKEN && opened_state  == LightBarrierState::BEAM_BROKEN)
                state = DoorState::ERROR_SOMETHING_BADLY_WRONG;
            else if (closed_state == LightBarrierState::BEAM_BROKEN && opened_state  == LightBarrierState::BEAM_SOLID)
                state = DoorState::CLOSED;
            else if (closed_state == LightBarrierState::BEAM_SOLID && opened_state  == LightBarrierState::BEAM_BROKEN)
                state = DoorState::OPENED;
            else 
                assert(!"well, two bits make four values");
            break;
        }
        case DoorState::CLOSED: {
            // "open" requested (button press). drive motor, and
            // switch state to "opening"
            if (do_open->get_state() == PushButtonState::PUSHBUTTON_PRESSED) {
                motor->forward();
                state = DoorState::OPENING;
            }

            // FIXME: what if user pressed "do_close" at the same
            // time?

            // FIXME: invariants
            break;
        }
        case DoorState::OPENING: {
            // see if we already reached the end position. if so, stop
            // motor and adjust door state.
            if (opened_position->get_state() == LightBarrierState::BEAM_BROKEN) {
                motor->stop();
                state = DoorState::OPENED;
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
