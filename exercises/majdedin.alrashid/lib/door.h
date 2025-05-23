
#pragma once
#include "motor.h"
#include "push-button.h"
#include "light-barrier.h"

class Door
{
public: 
    enum class State
    {
        INIT,
        CLOSED,
        OPENING,
        OPENED,
        ERROR_MIDDLE_POSITION,
        ERROR_SOMETHING_BADLY_WRONG,
    };

    Door(
        Motor* motor, 
        PushButton* do_close, 
        PushButton* do_open, 
        LightBarrier* closed_position, 
        LightBarrier* opened_position);

    void check();

    State getState() const;

private:
    Motor* motor;
    PushButton* do_close;
    PushButton* do_open;
    LightBarrier* closed_position;
    LightBarrier* opened_position;

    State state;
};