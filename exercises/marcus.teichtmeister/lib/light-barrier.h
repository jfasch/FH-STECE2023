#pragma once

enum LightBarrierState
{
    LIGHTBARRIER_BEAM_SOLID,
    LIGHTBARRIER_BEAM_BROKEN,
};

class LightBarrier
{
    public:
    virtual LightBarrierState get_state() const = 0;
    virtual void set_state(LightBarrierState state) = 0;
};