#include "light-barrier.h"

LightBarrier::~LightBarrier(){}

LightBarrier::LightBarrier(LightBarrierState state)
{
    _state = state;
}

LightBarrierState LightBarrier::LightBarrier_get_state() const
{
    return _state;
}

void LightBarrier::LightBarrier_set_state(LightBarrierState state)
{
    _state = state;
}