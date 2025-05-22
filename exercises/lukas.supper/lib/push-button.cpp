#include "push-button.h"

PushButton::PushButton(PushButtonState state)
{
    this->_state = state;
}

void PushButton::set_State(PushButtonState state)
{
    this->_state = state;
}

PushButton::~PushButton()
{
}

