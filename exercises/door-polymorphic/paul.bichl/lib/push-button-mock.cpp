#include "push-button-mock.h"

PushButton::State MockPushButton::get_state() const
{
    return _state;
}

void MockPushButton::set_state(State state)
{
    _state = state;
}
