#pragma once

#include "motor.h"
#include "push-button.h"
#include "light-barrier.h"
#include <assert.h>

enum DoorState
{
    DOOR_INIT,
    DOOR_CLOSED,
    DOOR_OPENING,
    DOOR_OPENED,
    DOOR_ERROR_MIDDLE_POSITION,
    DOOR_ERROR_SOMETHING_BADLY_WRONG,
};


class Door
{
private:
    DoorState state;
    Motor* motor;
    PushButton* do_close;
    PushButton* do_open;
    LightBarrier* closed_position;
    LightBarrier* opened_position;

    public:
    // Constructor
    Door(Motor* motor_set, PushButton* do_close_set, PushButton* do_open_set, LightBarrier* closed_position_set, LightBarrier* opened_position_set);

    void Door_check();

    DoorState State_Get() const;
};
