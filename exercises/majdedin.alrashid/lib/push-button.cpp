#include "push-button.h"

PushButton::PushButton(State initialState)
    : state(initialState)
{
}

PushButton::State PushButton::getState() const
{
    return state;
}

void PushButton::setState(State state)
{
    this->state = state;
}