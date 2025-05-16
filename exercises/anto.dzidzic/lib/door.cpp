#include "door.h"

#include <assert.h>

Door::Door(Motor* motor,
           PushButton* doClose,
           PushButton* doOpen,
           LightBarrier* closedPosition,
           LightBarrier* openedPosition)
    : motor(motor),
      doClose(doClose),
      doOpen(doOpen),
      closedPosition(closedPosition),
      openedPosition(openedPosition),
      state(State::INIT)
{
    // Assume motor is idle at startup. FIXME: is that assumption safe?
    //assert(motor->stop() == MOTOR_IDLE);
}

void Door::check() {
    switch (state) {
        case State::INIT: {
            auto closedBarrierState = closedPosition->getState();
            auto openedBarrierState = openedPosition->getState();

            if (closedBarrierState == LightBarrier::LIGHTBARRIER_BEAM_SOLID &&
                openedBarrierState == LightBarrier::LIGHTBARRIER_BEAM_SOLID) {
                state = State::ERROR_MIDDLE_POSITION;
            } else if (closedBarrierState == LightBarrier::LIGHTBARRIER_BEAM_BROKEN &&
                       openedBarrierState == LightBarrier::LIGHTBARRIER_BEAM_BROKEN) {
                state = State::ERROR_SOMETHING_BADLY_WRONG;
            } else if (closedBarrierState == LightBarrier::LIGHTBARRIER_BEAM_BROKEN &&
                       openedBarrierState == LightBarrier::LIGHTBARRIER_BEAM_SOLID) {
                state = State::CLOSED;
            } else if (closedBarrierState == LightBarrier::LIGHTBARRIER_BEAM_SOLID &&
                       openedBarrierState == LightBarrier::LIGHTBARRIER_BEAM_BROKEN) {
                state = State::OPENED;
            } else {
                assert(!"Invalid light barrier state combination");
            }
            break;
        }

        case State::CLOSED: {
            if (doOpen->PushButton_get_state() == PUSHBUTTON_PRESSED) {
                motor->forward();
                state = State::OPENING;
            }
            // FIXME: what if "doClose" is pressed at the same time?
            break;
        }

        case State::OPENING: {
            auto openedBarrierState = openedPosition->getState();
            if (openedBarrierState == LightBarrier::LIGHTBARRIER_BEAM_BROKEN) {
                motor->stop();
                state = State::OPENED;
            }
            break;
        }

        case State::OPENED:
        case State::ERROR_MIDDLE_POSITION:
        case State::ERROR_SOMETHING_BADLY_WRONG:
            assert(false); // Not handled yet
            break;
    }
}

Door::State Door::getState() const {
    return state;
}


