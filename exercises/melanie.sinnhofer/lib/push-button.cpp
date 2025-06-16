#include "push-button.h"

PushButton::PushButton(State state) // Class:: ImplementationVomKonstruktorPushButton(State state) - wird automatisch aufgerufen bei Objekterstellung
{
    state_ = state;
}

// get Methode - gibt aktuellen Zustand zurück
PushButton::State PushButton::get_state() const
{
    return state_;
}

// set Methode - ändert den Zustand (für Tests)
void PushButton::set_state(State state)
{
    state_ = state;
}
