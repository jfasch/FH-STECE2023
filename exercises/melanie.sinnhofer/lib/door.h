#pragma once

#include "motor.h"
#include "push-button.h"
#include "light-barrier.h"


class Door
{
public:
    enum class State
    {
        INIT,
        CLOSED,
        OPENING,
        OPENED,
        ERROR_MIDDLE_POSITION,
        ERROR_SOMETHING_BADLY_WRONG,
    };

    explicit Door(Motor* motor, 
                  PushButton* do_close, PushButton* do_open, 
                  LightBarrier* closed_position, LightBarrier* opened_position);

    void check();
    // for tests only
    State get_state() const;

private:
    Motor* motor_;
    PushButton* do_close_;
    PushButton* do_open_;
    LightBarrier* closed_position_;
    LightBarrier* opened_position_;

    State state_;
};