#include "door.h"

#include <assert.h>


Door::Door(Motor* motor, 
                PushButton* do_close,
                PushButton* do_open, 
                LightBarrier* closed_position, 
                LightBarrier* opened_position)
          : motor(motor),
            do_close(do_close),
            do_open(do_open),
            closed_position(closed_position),
            opened_position(opened_position),
            state(DOOR_INIT)
{
    // assume that the motor is idle when the software boots. FIXME:
    // is that assumption safe?
    assert(motor->get_direction() == MOTOR_IDLE);
}

void Door::check()
{
    switch (state) {
        case DOOR_INIT: {
            // figure out the state we are in: where is the door?
            LightBarrierState closed_barrier_state = closed_position->get_state();
            LightBarrierState opened_barrier_state = opened_position->get_state();

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
            if (PushButton_get_state(do_open) == PUSHBUTTON_PRESSED) {
                motor->forward();
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
            LightBarrierState opened_barrier_state = opened_position->get_state();
            if (opened_barrier_state == LIGHTBARRIER_BEAM_BROKEN) {
                motor->stop();
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
