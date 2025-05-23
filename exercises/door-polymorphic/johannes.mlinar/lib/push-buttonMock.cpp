#include "push-buttonMock.h"

PushButtonMock::PushButtonMock(PushButtonMock::State state)
{
    _state = state;
}

PushButtonMock::State PushButtonMock::get_state() const
{
    return _state;
}

void PushButtonMock::set_state(PushButtonMock::State state)
{
    _state = state;
}
