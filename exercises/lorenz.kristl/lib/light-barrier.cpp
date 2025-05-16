/*
#include "light-barrier.h"

void LightBarrier_init(LightBarrier* self, LightBarrierState state)
{
    self->state = state;
}

LightBarrierState LightBarrier_get_state(LightBarrier* self)
{
    return self->state;
}

void LightBarrier_set_state(LightBarrier* self, LightBarrierState state)
{
    self->state = state;
}
*/
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
