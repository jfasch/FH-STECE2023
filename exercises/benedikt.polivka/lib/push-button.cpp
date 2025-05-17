#include "push-button.h"

/*
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

PushButton::PushButton(PushButtonState state)
{
    _state = state;
}

PushButton::~PushButton()
{
}

PushButtonState PushButton::PushButton_get_state() const
{
    return _state;
}

void PushButton::PushButton_set_state(PushButtonState state)
{
    _state = state;
}
