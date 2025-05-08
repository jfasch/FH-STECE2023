#pragma once

#include "motor.h"
#include "push-button.h"
#include "light-barrier.h"

class Door
{
public:
    Door(Motor* motor, PushButton* do_close, PushButton* do_open, 
        LightBarrier* closed_position, LightBarrier* opened_position)
    {
        //todo: assert(Motor_get_direction(motor) == MOTOR_IDLE);
        _motor = motor;
        _do_close = do_close;
        _do_open = do_open;
        _closed = closed_position;
        _open = opened_position;

        _state = DOOR_INIT;
    }
    void Door_check();
    enum DoorState
    {
        DOOR_INIT,
        DOOR_CLOSED,
        DOOR_OPENING,
        DOOR_OPENED,
        DOOR_ERROR_MIDDLE_POSITION,
        DOOR_ERROR_SOMETHING_BADLY_WRONG,
    };

private:
    DoorState _state;
    Motor* _motor;
    PushButton* _do_close;
    PushButton* _do_open;
    LightBarrier* _closed;
    LightBarrier* _open;
};
