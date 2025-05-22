#include "light-barrier.h"


LightBarrier::LightBarrier(LightBarrierState state)
{
    state = state;
}

LightBarrierState LightBarrier::LightBarrier_get_state() const
{
    return state;
}

void LightBarrier::set_state(LightBarrierState state)
{
    state = state;
}
