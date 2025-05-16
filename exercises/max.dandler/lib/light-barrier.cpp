#include "light-barrier.h"


LightBarrier::LightBarrier(LightBarrierState state)
{
    _state = state;
}

LightBarrierState LightBarrier::get_state()
{
    return _state;
}

void LightBarrier::set_state(LightBarrierState state)
{
    _state = state;
}
