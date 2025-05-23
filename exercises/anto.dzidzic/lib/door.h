#pragma once
//asdads
#include "motor.h"
#include "push-button.h"
#include "light-barrier.h"

class Door {
public:
    enum class State {
        INIT,
        CLOSED,
        OPENING,
        OPENED,
        ERROR_MIDDLE_POSITION,
        ERROR_SOMETHING_BADLY_WRONG
    };

    Door(Motor* motor,
         PushButton* doClose,
         PushButton* doOpen,
         LightBarrier* closedPosition,
         LightBarrier* openedPosition);

    void check();
    State getState() const;

private:
    Motor* motor;
    PushButton* doClose;
    PushButton* doOpen;
    LightBarrier* closedPosition;
    LightBarrier* openedPosition;

    State state;
    //dasda
};

