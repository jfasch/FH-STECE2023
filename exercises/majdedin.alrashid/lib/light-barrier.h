#pragma once

enum LightBarrierState
{
    LIGHTBARRIER_BEAM_SOLID,
    LIGHTBARRIER_BEAM_BROKEN,
};

class LightBarrier
{
public:
    // Constructor replaces LightBarrier_init
    LightBarrier(LightBarrierState state);

    // Replaces LightBarrier_get_state
    LightBarrierState getState() const;

    // For tests only
    void setState(LightBarrierState state);

private:
    LightBarrierState state_;
};
