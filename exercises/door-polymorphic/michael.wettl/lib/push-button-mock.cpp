#include "push-button-mock.h"

PushButton_Mock::PushButton_Mock(State state)
{
    _state = state;
}

PushButton_Mock::State PushButton_Mock::get_state() const
{
    return _state;
}

void PushButton_Mock::set_state(State state)
{
    _state = state;
}
