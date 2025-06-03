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


    Door(IMotor* motor, 
         IPushButton* do_close, IPushButton* do_open,
         ILightBarrier* closed_position, ILightBarrier* opened_position);
    void check();

    // for tests only
    State get_state() const { return _state; }

private:
    IMotor* _motor;
    IPushButton* _do_close;
    IPushButton* _do_open;
    ILightBarrier* _closed_position;
    ILightBarrier* _opened_position;

    State _state;
};
