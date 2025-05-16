#pragma once


enum LightBarrierState
{
    LIGHTBARRIER_BEAM_SOLID,
    LIGHTBARRIER_BEAM_BROKEN,
};

class LightBarrier
{
    public:
        LightBarrier(LightBarrierState state) {_state =state;};
        LightBarrierState get_state() const { return _state; };
        void set_state(LightBarrierState state) { _state = state; };
    private:
        LightBarrierState _state;
};
