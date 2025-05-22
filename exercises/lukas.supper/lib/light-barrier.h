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
    LightBarrier(LightBarrierState state){this->_state = state;};
    LightBarrierState get_state(){return this->_state;};
    void set_State(LightBarrierState state){this->_state = state;};
};
