#include "light-barrier.h"

LightBarrier::LightBarrierState LightBarrier::LightBarrier_get_state()
{
    return _state;
}

void LightBarrier::LightBarrier_set_state(LightBarrierState state)
{
    _state = state;
}
