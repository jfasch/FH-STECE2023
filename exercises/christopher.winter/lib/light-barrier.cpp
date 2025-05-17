#include "light-barrier.h"

LightBarrier::LightBarrier(LightBarrierState stateInit)
{
    state = stateInit;
}

LightBarrierState LightBarrier::LightBarrier_get_state() const
{
    return state;
}

// for tests only
void LightBarrier::LightBarrier_set_state(LightBarrierState stateSet)
{
    state = stateSet;
}