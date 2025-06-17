#include <door/event-edge-detector.h>

EdgeDetector::EdgeDetector(PushButton* button)
{
    _button = button;
    _old_state = _button->get_state();
    _state = EdgeDetector::State::NONE;
}

EdgeDetector::State EdgeDetector::detect_edge()
{
    PushButton::State now_state = _button->get_state();
    if(_old_state == PushButton::State::RELEASED && now_state == PushButton::State::PRESSED)
    {
        return EdgeDetector::State::RISING;
    }
    else if(_old_state == PushButton::State::PRESSED && now_state == PushButton::State::RELEASED)
    {
        return EdgeDetector::State::FALLING;
    }
    else
    {
        return EdgeDetector::State::NONE;
    }
}