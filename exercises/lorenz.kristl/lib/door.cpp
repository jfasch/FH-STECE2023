/*
#include "door.h"
#include <assert.h>


void Door_init(Door* self, 
               Motor* motor, 
               PushButton* do_close, PushButton* do_open, 
               LightBarrier* closed_position, LightBarrier* opened_position)
{
    // assume that the motor is idle when the software boots. FIXME:
    // is that assumption safe?
    assert(Motor_get_direction(motor) == MOTOR_IDLE);

    self->motor = motor;
    self->do_close = do_close;
    self->do_open = do_open;
    self->closed_position = closed_position;
    self->opened_position = opened_position;

    self->state = DOOR_INIT;
}

void Door_check(Door* self)
{
    switch (self->state) {
        case DOOR_INIT: {
            // figure out the state we are in: where is the door?
            LightBarrierState closed_barrier_state = LightBarrier_get_state(self->closed_position);
            LightBarrierState opened_barrier_state = LightBarrier_get_state(self->opened_position);

            if (closed_barrier_state == LIGHTBARRIER_BEAM_SOLID && opened_barrier_state == LIGHTBARRIER_BEAM_SOLID)
                self->state = DOOR_ERROR_MIDDLE_POSITION;   // FIXME: recover from that
            else if (closed_barrier_state == LIGHTBARRIER_BEAM_BROKEN && opened_barrier_state == LIGHTBARRIER_BEAM_BROKEN)
                self->state = DOOR_ERROR_SOMETHING_BADLY_WRONG;
            else if (closed_barrier_state == LIGHTBARRIER_BEAM_BROKEN && opened_barrier_state == LIGHTBARRIER_BEAM_SOLID)
                self->state = DOOR_CLOSED;
            else if (closed_barrier_state == LIGHTBARRIER_BEAM_SOLID && opened_barrier_state == LIGHTBARRIER_BEAM_BROKEN)
                self->state = DOOR_OPENED;
            else 
                assert(!"well, two bits make four values");
            break;
        }
        case DOOR_CLOSED: {
            // "open" requested (button press). drive motor, and
            // switch state to "opening"
            if (PushButton_get_state(self->do_open) == PUSHBUTTON_PRESSED) {
                Motor_forward(self->motor);
                self->state = DOOR_OPENING;
            }

            // FIXME: what if user pressed "do_close" at the same
            // time?

            // FIXME: invariants
            break;
        }
        case DOOR_OPENING: {
            // see if we already reached the end position. if so, stop
            // motor and adjust door state.
            LightBarrierState opened_barrier_state = LightBarrier_get_state(self->opened_position);
            if (opened_barrier_state == LIGHTBARRIER_BEAM_BROKEN) {
                Motor_stop(self->motor);
                self->state = DOOR_OPENED;
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
*/

#include "door.h"
#include "cassert"

Door::Door(
    Motor* motor, 
    PushButton* do_close, 
    PushButton* do_open, 
    LightBarrier* closed_position, 
    LightBarrier* opened_position)
    : motor(motor), 
      do_close(do_close), 
      do_open(do_open), 
      closed_position(closed_position), 
      opened_position(opened_position), 
      state(State::INIT)
{
    // Assume that the motor is idle when the software boots.
    assert(motor->getDirection() == Motor::Direction::IDLE);
}

void Door::check()
{
    switch (state) {
        case State::INIT: {
            // Determine the initial state of the door based on light barriers.
            LightBarrier::State closed_barrier_state = closed_position->getState();
            LightBarrier::State opened_barrier_state = opened_position->getState();

            if (closed_barrier_state == LightBarrier::State::BEAM_SOLID && 
                opened_barrier_state == LightBarrier::State::BEAM_SOLID) {
                state = State::ERROR_MIDDLE_POSITION; // FIXME: recover from this
            } else if (closed_barrier_state == LightBarrier::State::BEAM_BROKEN && 
                       opened_barrier_state == LightBarrier::State::BEAM_BROKEN) {
                state = State::ERROR_SOMETHING_BADLY_WRONG;
            } else if (closed_barrier_state == LightBarrier::State::BEAM_BROKEN && 
                       opened_barrier_state == LightBarrier::State::BEAM_SOLID) {
                state = State::CLOSED;
            } else if (closed_barrier_state == LightBarrier::State::BEAM_SOLID && 
                       opened_barrier_state == LightBarrier::State::BEAM_BROKEN) {
                state = State::OPENED;
            } else {
                assert(!"Unexpected light barrier state");
            }
            break;
        }
        case State::CLOSED: {
            // Handle "open" button press to start opening the door.
            if (do_open->getState() == PushButton::State::PRESSED) {
                motor->forward();
                state = State::OPENING;
            }

            // FIXME: Handle simultaneous "do_close" button press.
            if (do_open->getState() == PushButton::State::PRESSED &&
                do_close->getState() == PushButton::State::PRESSED) {
                // Do nothing for "do_close".
            } else if (do_close->getState() == PushButton::State::PRESSED) {
                // For now, do nothing.
            }

            // FIXME: Add invariants.
            // Check if the door is in the closed position.

            break;
        }
        case State::OPENING: {
            // Check if the door has reached the open position.
            LightBarrier::State opened_barrier_state = opened_position->getState();
            if (opened_barrier_state == LightBarrier::State::BEAM_BROKEN) {
                motor->stop();
                state = State::OPENED;
            }

            // FIXME: Add invariants.

            // Handle "do_close" button press while opening.

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

Door::State Door::getState() const
{
    return state;
}