/*
#include "push-button.h"

void PushButton_init(PushButton* self, PushButtonState state)
{
    self->state = state;
}

PushButtonState PushButton_get_state(PushButton* self)
{
    return self->state;
}

void PushButton_set_state(PushButton* self, PushButtonState state)
{
    self->state = state;
}
*/
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