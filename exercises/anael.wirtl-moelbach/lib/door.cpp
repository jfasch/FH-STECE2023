#include "door.h"
#include <cassert>

void Door::check() {
    switch (state) {
        case DoorState::DOOR_INIT: {
            LightBarrier::LightBarrierState closed_state = closed_position->get_state();
            LightBarrier::LightBarrierState opened_state = opened_position->get_state();

            if (closed_state == LightBarrier::LightBarrierState::LIGHTBARRIER_BEAM_SOLID &&
                opened_state == LightBarrier::LightBarrierState::LIGHTBARRIER_BEAM_SOLID) {
                state = DoorState::DOOR_ERROR_MIDDLE_POSITION;
            } else if (closed_state == LightBarrier::LightBarrierState::LIGHTBARRIER_BEAM_BROKEN &&
                       opened_state == LightBarrier::LightBarrierState::LIGHTBARRIER_BEAM_BROKEN) {
                state = DoorState::DOOR_ERROR_SOMETHING_BADLY_WRONG;
            } else if (closed_state == LightBarrier::LightBarrierState::LIGHTBARRIER_BEAM_BROKEN &&
                       opened_state == LightBarrier::LightBarrierState::LIGHTBARRIER_BEAM_SOLID) {
                state = DoorState::DOOR_CLOSED;
            } else if (closed_state == LightBarrier::LightBarrierState::LIGHTBARRIER_BEAM_SOLID &&
                       opened_state == LightBarrier::LightBarrierState::LIGHTBARRIER_BEAM_BROKEN) {
                state = DoorState::DOOR_OPENED;
            } else {
                assert(!"well, two bits make four values");
            }
            break;
        }

        case DoorState::DOOR_CLOSED: {
            if (do_open->get_state() == PushButton::PushButtonState::PUSHBUTTON_PRESSED) {
                motor->forward();
                state = DoorState::DOOR_OPENING;
            }

            break;
        }

        case DoorState::DOOR_OPENING: {
            if (opened_position->get_state() == LightBarrier::LightBarrierState::LIGHTBARRIER_BEAM_BROKEN) {
                motor->stop();
                state = DoorState::DOOR_OPENED;
            }

            break;
        }

        case DoorState::DOOR_OPENED:
        case DoorState::DOOR_ERROR_MIDDLE_POSITION:
        case DoorState::DOOR_ERROR_SOMETHING_BADLY_WRONG: {
            assert(false);
            break;
        }
    }
}
