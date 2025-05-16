#pragma once

#include "motor.h"
#include "push-button.h"
#include "light-barrier.h"


enum DoorState
{
    DOOR_INIT,
    DOOR_CLOSED,
    DOOR_CLOSING,
    DOOR_OPENING,
    DOOR_OPENED,
    DOOR_ERROR_MIDDLE_POSITION,
    DOOR_ERROR_SOMETHING_BADLY_WRONG,
};

class Door
{
private:
    Motor* _motor;
    PushButton* _do_close;
    PushButton* _do_open;
    LightBarrier* _closed_position;
    LightBarrier* _opened_position;

    DoorState _state;

public:
    Door(Motor* motor, PushButton* do_close, PushButton* do_open, 
        LightBarrier* closed_position, LightBarrier* opened_position);
    void check();

    //for tests only
    DoorState get_state();
};


