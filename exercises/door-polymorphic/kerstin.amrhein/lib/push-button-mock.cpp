#include "push-button.h"
#include "push-button-mock.h"

PushButtonMock::PushButtonMock(PushButton::State state)
{
    _state = state;
}

PushButton::State PushButtonMock::get_state() const
{
    return _state;
}

void PushButtonMock::set_state(PushButton::State state)
{
    _state = state;
}
