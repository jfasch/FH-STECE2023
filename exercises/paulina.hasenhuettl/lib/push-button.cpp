#include "push-button.h"

PushButton::PushButton(PushButtonState state): _state(state)
{
    
}

PushButtonState PushButton::get_state() const
{
    return _state;
}

void PushButton::set_state(PushButtonState state)
{
    _state = state;
}


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