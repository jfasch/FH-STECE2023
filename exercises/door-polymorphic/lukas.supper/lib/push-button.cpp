#include "push-button.h"

PushButton::PushButton(State state)
{
    _state = state;
}

PushButton::State PushButton::get_state() const
{
    return _state;
}

void PushButton::set_state(State state)
{
    _state = state;
}
