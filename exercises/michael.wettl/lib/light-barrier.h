#pragma once


enum class LightBarrierState
{
    LIGHTBARRIER_BEAM_SOLID,
    LIGHTBARRIER_BEAM_BROKEN,
};

class LightBarrier
{
    private:
        LightBarrierState _state;
    
    public:
        LightBarrier(LightBarrierState state);
        LightBarrierState get_state() const {return _state;};
        // for tests only
        void set_state(LightBarrierState state) {_state = state;};
};
