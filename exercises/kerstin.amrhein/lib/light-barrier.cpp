#include "light-barrier.h"


LightBarrier::LightBarrier(LightBarrierState init_state)
{
    _state = init_state;
}

LightBarrierState LightBarrier::get_state()
{
    return _state;
}

void LightBarrier::set_state(LightBarrierState state)
{
    _state = state;
}
