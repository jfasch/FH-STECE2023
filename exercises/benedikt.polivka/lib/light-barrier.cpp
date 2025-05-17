#include "light-barrier.h"

/*
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

LightBarrier::LightBarrier(LightBarrierState state)
{
    _state = state;
}

LightBarrier::~LightBarrier()
{
}

LightBarrierState LightBarrier::LightBarrier_get_state() const
{
    return _state;
}

void LightBarrier::LightBarrier_set_state(LightBarrierState state)
{
    _state = state;
}