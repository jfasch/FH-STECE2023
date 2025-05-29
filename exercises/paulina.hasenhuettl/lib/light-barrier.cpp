#include "light-barrier.h"

LightBarrier::LightBarrier(LightBarrierState state)
    : _state(state)
{
}

LightBarrierState LightBarrier::get_state() const
{
    return _state;
}

void LightBarrier::set_state(LightBarrierState state)
{
    _state = state;
}


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