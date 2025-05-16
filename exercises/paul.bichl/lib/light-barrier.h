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
        LightBarrierState get_state() const { return state_; };
        void set_state(LightBarrierState state) { state_ = state; };
    private:
        LightBarrierState state_;
};
