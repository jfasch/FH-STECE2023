#pragma once

#include "motor.h"
#include "push-button.h"
#include "light-barrier.h"

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

enum DoorState{
    DOOR_INIT,
    DOOR_CLOSED,
    DOOR_OPENING,
    DOOR_OPENED,
    DOOR_ERROR_MIDDLE_POSITION,
    DOOR_ERROR_SOMETHING_BADLY_WRONG
};

class Door{

    private:
        Motor* motor;
        PushButton* do_close;
        PushButton* do_open;
        LightBarrier* closed_position;
        LightBarrier* opened_position;

        DoorState state;

    public:
        Door(Motor* motor, PushButton* do_close, PushButton* do_open, LightBarrier* closed_position, LightBarrier* open_position){
            this->motor = motor;
            this->do_close = do_close;
            this->do_open = do_open;
            this->closed_position = closed_position;
            this->opened_position = open_position;
            this->state = state;
        }

        ~Door();
        void Door_check();
};