#pragma once

#include "motor.h"
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

        // for testing
        DoorState get_state() const { return _state; };
};

