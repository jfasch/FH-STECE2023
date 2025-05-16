#include "push-button.h"

PushButton::~PushButton(){}

PushButton::PushButton(PushButtonState state)
{
    _state = state;
}

PushButtonState PushButton::PushButton_get_state() const
{
    return _state;
}

void PushButton::PushButton_set_state(PushButtonState state)
{
    _state = state;
}
