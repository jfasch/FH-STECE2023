#pragma once
#include <light-barrier.h>

class LightBarrierMock : public LightBarrier
{
    private: 
    LightBarrier::State _state;

    public:
    LightBarrierMock(LightBarrier::State state) {_state = state;}
    LightBarrier::State get_state() const {return _state;}
    void set_state(LightBarrier::State state) {_state = state;}

};
