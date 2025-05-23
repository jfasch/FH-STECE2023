#pragma once

#include "motor.h"
#include "push-button.h"
#include "light-barrier.h"
#include <assert.h>


enum class DoorState {
    INIT,
    CLOSED,
    OPENING,
    OPENED,
    ERROR_MIDDLE_POSITION,
    ERROR_SOMETHING_BADLY_WRONG,
};

class Door {
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
            state(DoorState::INIT) {
                assert(motor->getDirection() == MotorDirection::IDLE);
            }
    
        void check();
    
        DoorState getState() const { return state; }
    
    private:
        Motor* motor;
        PushButton* do_close;
        PushButton* do_open;
        LightBarrier* closed_position;
        LightBarrier* opened_position;
    
        DoorState state;
    };
