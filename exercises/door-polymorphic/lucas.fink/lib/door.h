#pragma once

#include "motor.h"
#include "push-button.h"
#include "light-barrier.h"



class Door
{
public:
    enum State
    {
        INIT,
        CLOSED,
        OPENING,
        OPENED,
        ERROR_MIDDLE_POSITION,
        ERROR_SOMETHING_BADLY_WRONG,
    };


    Door(Motor* motor, 
         PushButton* do_close, PushButton* do_open,
         LightBarrier* closed_position, LightBarrier* opened_position);
    void check();

    // for tests only
    State get_state() const { return _state; }

private:
    Motor* _motor;
    PushButton* _do_close;
    PushButton* _do_open;
    LightBarrier* _closed_position;
    LightBarrier* _opened_position;

    State _state;
};
