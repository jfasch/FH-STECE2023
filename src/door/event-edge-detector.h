#pragma once

#include <door/push-button.h>
#include <door/timespec.h>

class EdgeDetector
{
public:
    enum State
    {
        RISING,
        FALLING,
        NONE
    };

    EdgeDetector(PushButton* button, const TimeSpec& debounce_time);
    State detect_edge(const TimeSpec& now);

private:
    PushButton::State _old_state;
    PushButton* _button;
    State _state;

    TimeSpec _debounce;
    TimeSpec _old_time;
};