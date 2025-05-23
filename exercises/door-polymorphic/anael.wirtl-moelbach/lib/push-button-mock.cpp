#include "push-button.h"
#include "push-button-mock.h"

PushButtonMock::PushButtonMock(State state)
{
    _state = state;
}

PushButtonMock::State PushButtonMock::get_state() const
{
    return _state;
}

void PushButtonMock::set_state(State state)
{
    _state = state;
}
