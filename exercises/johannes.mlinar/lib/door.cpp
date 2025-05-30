#include "door.h"

void Door::check() {
    switch (state) {
        case DoorState::INIT: {
            auto closedState = closedPosition->getState();
            auto openedState = openedPosition->getState();

            if (closedState == LightBarrierState::BEAM_SOLID &&
                openedState == LightBarrierState::BEAM_SOLID) {
                state = DoorState::ERROR_MIDDLE_POSITION;
            } else if (closedState == LightBarrierState::BEAM_BROKEN &&
                       openedState == LightBarrierState::BEAM_BROKEN) {
                state = DoorState::ERROR_SOMETHING_BADLY_WRONG;
            } else if (closedState == LightBarrierState::BEAM_BROKEN &&
                       openedState == LightBarrierState::BEAM_SOLID) {
                state = DoorState::CLOSED;
            } else if (closedState == LightBarrierState::BEAM_SOLID &&
                       openedState == LightBarrierState::BEAM_BROKEN) {
                state = DoorState::OPENED;
            } else {
                assert(!"Unreachable state combination");
            }
            break;
        }

        case DoorState::CLOSED: {
            if (doOpen->getState() == PushButtonState::PRESSED) {
                motor->forward();
                state = DoorState::OPENING;
            }
            break;
        }

        case DoorState::OPENING: {
            if (openedPosition->getState() == LightBarrierState::BEAM_BROKEN) {
                motor->stop();
                state = DoorState::OPENED;
            }
            break;
        }

        case DoorState::OPENED:
        case DoorState::ERROR_MIDDLE_POSITION:
        case DoorState::ERROR_SOMETHING_BADLY_WRONG: {
            assert(false); // Not yet implemented
            break;
        }
    }
}
