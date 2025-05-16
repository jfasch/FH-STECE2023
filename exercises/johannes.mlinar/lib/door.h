#pragma once

#include "motor.h"
#include "push-button.h"
#include "light-barrier.h"
#include <cassert>

enum class DoorState {
    INIT,
    CLOSED,
    OPENING,
    OPENED,
    ERROR_MIDDLE_POSITION,
    ERROR_SOMETHING_BADLY_WRONG
};

class Door {
public:
    Door(Motor* motor, PushButton* closeBtn, PushButton* openBtn,
         LightBarrier* closedSensor, LightBarrier* openedSensor)
        : motor(motor), doClose(closeBtn), doOpen(openBtn),
          closedPosition(closedSensor), openedPosition(openedSensor),
          state(DoorState::INIT) {
        assert(motor->getDirection() == MotorDirection::IDLE);
    }

    void check();

private:
    Motor* motor;
    PushButton* doClose;
    PushButton* doOpen;
    LightBarrier* closedPosition;
    LightBarrier* openedPosition;
    DoorState state;
};
