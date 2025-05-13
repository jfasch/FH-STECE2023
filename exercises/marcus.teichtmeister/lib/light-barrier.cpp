#include "light-barrier.h"


LightBarrier::LightBarrier(LightBarrierState state)
{
    _state = state;
}

void LightBarrier::LightBarrier_set_state(LightBarrierState state)
{
    _state = state;
}
