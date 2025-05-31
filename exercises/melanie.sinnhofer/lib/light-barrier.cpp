#include "light-barrier.h"


LightBarrier::LightBarrier(State state)
{
    state_ = state;
}

// get Methode - gibt aktuellen Zustand zurück
LightBarrier::State LightBarrier::get_state() const
{
    return state_;
}

// set Methode - ändert den Zustand (für Tests)
void LightBarrier::set_state(State state)
{
    state_ = state;
}
