#include "light-barrier.h"


LightBarrier::LightBarrier(LightBarrierState stateInit)
{
    state = stateInit;
}

LightBarrierState LightBarrier::get_state() const
{
    return state;
}

void LightBarrier::set_state(LightBarrierState stateSet)
{
    state = stateSet;
}
