#pragma once

enum LightBarrierState
{
    LIGHTBARRIER_BEAM_SOLID,
    LIGHTBARRIER_BEAM_BROKEN,
};

struct LightBarrier
{
    LightBarrierState state;
};

void LightBarrier_init(LightBarrier* self, LightBarrierState state);
LightBarrierState LightBarrier_get_state(LightBarrier* self);
// for tests only
void LightBarrier_set_state(LightBarrier* self, LightBarrierState state);