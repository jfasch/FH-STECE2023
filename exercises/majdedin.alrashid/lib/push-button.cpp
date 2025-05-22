#include "push-button.h"

PushButton::PushButton(PushButtonState state)
    : state_(state)
{
}

PushButtonState PushButton::getState() const
{
    return state_;
}

void PushButton::setState(PushButtonState state)
{
    state_ = state;
}
