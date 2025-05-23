#include "light-barrier.h"


LightBarrier::LightBarrier(LightBarrierState state) : state(state) {}

LightBarrierState LightBarrier::get_state() const
{
    return state;
}

void LightBarrier::set_state(LightBarrierState new_state)
{
    state = new_state;
}
