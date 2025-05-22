#include "light-barrier.h"


// Konstruktor
LightBarrier::LightBarrier(LightBarrierState state)
{
    _state = state;
}

// Getter
LightBarrierState LightBarrier::state() const
{
    return _state;
}

// Setter
void LightBarrier::set_state(LightBarrierState state)
{
    _state = state;
}