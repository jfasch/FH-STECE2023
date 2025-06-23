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
    EdgeDetector::State edge;
    if(_old_state == PushButton::State::RELEASED && now_state == PushButton::State::PRESSED)
    {
        edge = EdgeDetector::State::RISING;
    }
    else if(_old_state == PushButton::State::PRESSED && now_state == PushButton::State::RELEASED)
    {
        edge = EdgeDetector::State::FALLING;
    }
    else
    {
        edge = EdgeDetector::State::NONE;
    }
    _old_state = now_state;
    return edge;
}