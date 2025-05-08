#include "push-button.h"

PushButton::PushButtonState PushButton::PushButton_get_state()
{
    return _state;
}

void PushButton::PushButton_set_state(PushButton::PushButtonState state)
{
    _state = state;
}
