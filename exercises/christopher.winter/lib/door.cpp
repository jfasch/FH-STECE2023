#include "door.h"
#include <cassert>

Door::Door(Motor* motor_set, PushButton* do_close_set, PushButton* do_open_set, LightBarrier* closed_position_set, LightBarrier* opened_position_set)
    : motor(motor_set), do_close(do_close_set), do_open(do_open_set),
      closed_position(closed_position_set), opened_position(opened_position_set)
{
    assert(motor_set->Motor_get_direction() == MOTOR_IDLE);
    state = DOOR_INIT;
}

void Door::Door_check()
{
    switch (state) {
        case DOOR_INIT: {
            // figure out the state we are in: where is the door?
            LightBarrierState closed_barrier_state = closed_position->LightBarrier_get_state();
            LightBarrierState opened_barrier_state = opened_position->LightBarrier_get_state();

            if (closed_barrier_state == LIGHTBARRIER_BEAM_SOLID && opened_barrier_state == LIGHTBARRIER_BEAM_SOLID)
                state = DOOR_ERROR_MIDDLE_POSITION;   // FIXME: recover from that
            else if (closed_barrier_state == LIGHTBARRIER_BEAM_BROKEN && opened_barrier_state == LIGHTBARRIER_BEAM_BROKEN)
                state = DOOR_ERROR_SOMETHING_BADLY_WRONG;
            else if (closed_barrier_state == LIGHTBARRIER_BEAM_BROKEN && opened_barrier_state == LIGHTBARRIER_BEAM_SOLID)
                state = DOOR_CLOSED;
            else if (closed_barrier_state == LIGHTBARRIER_BEAM_SOLID && opened_barrier_state == LIGHTBARRIER_BEAM_BROKEN)
                state = DOOR_OPENED;
            else
                assert(!"well, two bits make four values");
            break;
        }
        case DOOR_CLOSED: {
            // "open" requested (button press). drive motor, and
            // switch state to "opening"
            
            if (do_open->getState() == PUSHBUTTON_PRESSED) {
                assert(do_open->getState() == PUSHBUTTON_PRESSED);
                motor->Motor_forward();
                state = DOOR_OPENING;
            }

            // FIXME: what if user pressed "do_close" at the same
            // time?

            // FIXME: invariants
            break;
        }
        case DOOR_OPENING: {
            // see if we already reached the end position. if so, stop
            // motor and adjust door state.
            LightBarrierState opened_barrier_state = opened_position->LightBarrier_get_state();
            if (opened_barrier_state == LIGHTBARRIER_BEAM_BROKEN) {
                motor->Motor_stop();
                state = DOOR_OPENED;
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

DoorState Door::State_Get() const
{
    return state;
}
