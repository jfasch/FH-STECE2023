#include "push-button.h"

//Initialisiert Button
PushButton::PushButton(PushButtonState state)
{
    _state = state;
}

//liest aktuellen state aus 
PushButtonState PushButton::get_state()
{
    return _state;
}

//Setzt einen neuen state 
void PushButton::set_state(PushButtonState state)
{
    _state = state;
}