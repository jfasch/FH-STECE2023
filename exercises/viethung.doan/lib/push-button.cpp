#include "push-button.h"

// Konstruktor
PushButton::PushButton(PushButtonState state)
{
    _state = state;
}

// Getter
PushButtonState PushButton::state() const
{
    return _state;
}

// Setter
void PushButton::set_state(PushButtonState state)
{
    _state = state;
}
