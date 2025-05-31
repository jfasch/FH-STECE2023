#pragma once

#include "motor.h"
#include "push-button.h"
#include "light-barrier.h"


enum DoorState
{
    DOOR_INIT,
    DOOR_CLOSED,
    DOOR_OPENING,
    DOOR_OPENED,
    DOOR_ERROR_MIDDLE_POSITION,
    DOOR_ERROR_SOMETHING_BADLY_WRONG,
};

struct Door
{
    Motor* motor;
    PushButton* do_close;
    PushButton* do_open;
    LightBarrier* closed_position;
    LightBarrier* opened_position;

    DoorState state;
};

void Door_init(Door* self, 
               Motor* motor, 
               PushButton* do_close, PushButton* do_open, 
               LightBarrier* closed_position, LightBarrier* opened_position);

void Door_check(Door* door);
