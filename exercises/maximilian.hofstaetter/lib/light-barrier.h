#pragma once

enum LightBarrierState
{
    LIGHTBARRIER_BEAM_SOLID,
    LIGHTBARRIER_BEAM_BROKEN,
};

class LightBarrier{

    private:
        LightBarrierState _state;

    public:

        ~LightBarrier();
        LightBarrier(LightBarrierState state);
        LightBarrierState LightBarrier_get_state() const;
        void LightBarrier_set_state(LightBarrierState state);
};