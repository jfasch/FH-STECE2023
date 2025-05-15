#pragma once

extern "C" {
    #include "motor.h"
    //#include "push-button.h"
    //#include "light-barrier.h"
    //#include "door.h"
}


#include "push-button.h"
#include "light-barrier.h"

enum class DoorState
{
    INIT,
    CLOSED,
    OPENING,
    OPENED,
    ERROR_MIDDLE_POSITION,
    ERROR_SOMETHING_BADLY_WRONG,
};

class Door
{
public:
    Door(Motor* motor,PushButton* do_close, PushButton* do_open,LightBarrier* closed_position, LightBarrier* opened_position);

    DoorState get_state() const { return _state; } //Getter um auf DoorState _state zugreifen zu können (lesen)

    void check();

private:
    Motor* _motor;
    PushButton* _do_close;
    PushButton* _do_open;
    LightBarrier* _closed_position;
    LightBarrier* _opened_position;

    DoorState _state;
};

/*
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
*/