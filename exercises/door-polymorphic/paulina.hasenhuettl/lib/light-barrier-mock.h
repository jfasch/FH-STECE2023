#pragma once
#include <light-barrier.h>

class LightBarrierMock: public LightBarrier
{
public:
    
    explicit LightBarrierMock(State state);
    State get_state() const override;

    void set_state(State state) override;

private:
    State _state;
};


   