#include "light-barrier.h"

LightBarrier::LightBarrier(State initialState)
    : state(initialState)
{
}

LightBarrier::State LightBarrier::getState() const
{
    return state;
}

void LightBarrier::setState(State state)
{
    this->state = state;
}