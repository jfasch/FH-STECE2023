
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