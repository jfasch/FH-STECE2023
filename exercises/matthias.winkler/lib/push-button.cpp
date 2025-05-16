#include "push-button.h"

PushButton::PushButton(PushButtonState state) : state(state) {}

PushButtonState PushButton::get_state() const
{
    return state;
} 

void PushButton::set_state(PushButtonState new_state)
{
    state = new_state;
}
