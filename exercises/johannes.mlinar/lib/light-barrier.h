#pragma once

class LightBarrier{
    public:
    enum LightBarrierState
    {
    LIGHTBARRIER_BEAM_SOLID,
    LIGHTBARRIER_BEAM_BROKEN,
    };
    LightBarrier(LightBarrierState state){
        _state=state;
    }
    LightBarrierState LightBarrier_get_state();
    void LightBarrier_set_state(LightBarrierState state);

    private:
    LightBarrierState _state;

};
