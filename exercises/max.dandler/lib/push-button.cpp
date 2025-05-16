#include "push-button.h"

PushButton::PushButton(PushButtonState state)
{
    _state = state;
}

PushButtonState PushButton::get_state()
{
    return _state;
}

void PushButton::set_state(PushButtonState state)
{
    _state = state;
}
