#include "push-button-mock.h"

MockPushButton::MockPushButton(PushButton::State state)
{
    _state = state;
}

PushButton::State MockPushButton::get_state() const
{
    return _state;
}

void MockPushButton::set_state(PushButton::State state)
{
    _state = state;
}
