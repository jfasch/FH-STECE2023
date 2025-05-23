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