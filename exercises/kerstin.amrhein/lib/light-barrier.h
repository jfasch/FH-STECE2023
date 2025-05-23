#pragma once


enum LightBarrierState
{
    LIGHTBARRIER_BEAM_SOLID,
    LIGHTBARRIER_BEAM_BROKEN,
};

class LightBarrier
{
private:
    LightBarrierState _state;

public:
    LightBarrier(LightBarrierState init_state);

    LightBarrierState get_state();

    // for tests only
    void set_state(LightBarrierState state);
};


