#pragma once

#include "motor.h"
#include "push-button.h"
#include "light-barrier.h"

class Door{
public:
enum class DoorState
{
    DOOR_INIT,
    DOOR_CLOSED,
    DOOR_OPENING,
    DOOR_OPENED,
    DOOR_ERROR_MIDDLE_POSITION,
    DOOR_ERROR_SOMETHING_BADLY_WRONG,
};

private:
Motor* motor;
    PushButton* do_close;
    PushButton* do_open;
    LightBarrier* closed_position;
    LightBarrier* opened_position;

    DoorState state;

public: 


Door(Motor* motor,  
    PushButton* do_close,
    PushButton* do_open,
    LightBarrier* closed_position,
    LightBarrier* opened_position)
    : motor(motor),
    do_close(do_close),
    do_open(do_open),
    closed_position(closed_position),
    opened_position(opened_position),

    state(DoorState::DOOR_INIT) {}

    void check();

    DoorState get_state() const {
        return state;
    }

};


