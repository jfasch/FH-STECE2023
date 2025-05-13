#include "push-button.h"

PushButton::PushButton(PushButtonState state)
{
    _state = state;
}

void PushButton::PushButton_set_state(PushButtonState state)
{
    _state = state;
}
