#pragma once


enum LightBarrierState
{
    LIGHTBARRIER_BEAM_SOLID,
    LIGHTBARRIER_BEAM_BROKEN,
};

class LightBarrier
{
    private:
        LightBarrierState state;

    public:
        LightBarrier(LightBarrierState stateInit);

        LightBarrierState LightBarrier_get_state() const;

        // for tests only
        void LightBarrier_set_state(LightBarrierState stateSet);

};




