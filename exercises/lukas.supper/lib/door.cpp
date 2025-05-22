#include "door.h"
#include "light-barrier.h"
#include "motor.h"
#include "push-button.h"


#include <assert.h>


Door::Door(Motor* motor, PushButton* do_close, PushButton* do_open, 
    LightBarrier* closed_position, LightBarrier* opened_position)
{
    assert(motor->get_direction() == MOTOR_IDLE);

    this->motor = motor;
    this->do_close = do_close;
    this->do_open = do_open;
    this->closed_position = closed_position;
    this->opened_position = opened_position;

    this->_state = DOOR_INIT;
}

void Door::check()
{
    switch (this->_state) {
        case DOOR_INIT: {
            // figure out the state we are in: where is the door?
            LightBarrierState closed_barrier_state = this->closed_position->get_state();
            LightBarrierState opened_barrier_state = this->opened_position->get_state();

            if (closed_barrier_state == LIGHTBARRIER_BEAM_SOLID && opened_barrier_state == LIGHTBARRIER_BEAM_SOLID)
                this->_state = DOOR_ERROR_MIDDLE_POSITION;   // FIXME: recover from that
            else if (closed_barrier_state == LIGHTBARRIER_BEAM_BROKEN && opened_barrier_state == LIGHTBARRIER_BEAM_BROKEN)
                this->_state = DOOR_ERROR_SOMETHING_BADLY_WRONG;
            else if (closed_barrier_state == LIGHTBARRIER_BEAM_BROKEN && opened_barrier_state == LIGHTBARRIER_BEAM_SOLID)
                this->_state = DOOR_CLOSED;
            else if (closed_barrier_state == LIGHTBARRIER_BEAM_SOLID && opened_barrier_state == LIGHTBARRIER_BEAM_BROKEN)
                this->_state = DOOR_OPENED;
            else 
                assert(!"well, two bits make four values");
            break;
        }
        case DOOR_CLOSED: {
            // "open" requested (button press). drive motor, and
            // switch state to "opening"
          if(this->do_open->get_state() == PUSHBUTTON_PRESSED) {
                this->motor->forward();
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
            LightBarrierState opened_barrier_state = opened_position->get_state();
            if (opened_barrier_state == LIGHTBARRIER_BEAM_BROKEN) {
                this->motor->stop();
                this->_state = DOOR_OPENED;
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
