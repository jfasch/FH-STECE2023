#pragma once
#include <light-barrier.h>

class LightBarrierMock : public LightBarrier
{
    private: 
    LightBarrierState _state;

    public:
    LightBarrierMock(LightBarrierState state) {_state = state;}
    LightBarrierState get_state() const {return _state;}
    void set_state(LightBarrierState state) {_state = state;}

};
