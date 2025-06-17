#pragma once

#include <door/push-button.h>

class EdgeDetector
{
public:
    enum State
    {
        RISING,
        FALLING,
        NONE
    };

    EdgeDetector(PushButton* button);
    State detect_edge();

private:
    PushButton::State _old_state;
    PushButton* _button;
    State _state;
};