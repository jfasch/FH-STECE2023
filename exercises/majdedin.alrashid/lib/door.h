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

class Door
{
public:
  
    Door(Motor* motor,
         PushButton* do_close, PushButton* do_open,
         LightBarrier* closed_position, LightBarrier* opened_position);

    void check();                    // Replaces Door_check
    DoorState getState() const;      // Optional: For inspection/testing

private:
    Motor* motor_;
    PushButton* do_close_;
    PushButton* do_open_;
    LightBarrier* closed_position_;
    LightBarrier* opened_position_;

    DoorState state_;
};
