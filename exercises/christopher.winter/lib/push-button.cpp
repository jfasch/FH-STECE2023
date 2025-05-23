#include "push-button.h"

PushButton::PushButton(PushButtonState initialState)
{
    state = initialState;
}

// Getter for the state
PushButtonState PushButton::getState() const
{
    return state;
}

// Setter for the state (for tests only)
void PushButton::setState(PushButtonState newState)
{
    state = newState;
        
}