#include "light-barrier.h"

LightBarrier::LightBarrier(LightBarrierState state)
    : state_(state)
{
}

LightBarrierState LightBarrier::getState() const
{
    return state_;
}

void LightBarrier::setState(LightBarrierState state)
{
    state_ = state;
}
