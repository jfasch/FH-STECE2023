#pragma once

#include "light-barrier.h"

class LightBarrierMock : public LightBarrier
{
public:
    LightBarrierMock(LightBarrier::State state);
    
    LightBarrier::State get_state() const;

    // for tests only
    void set_state(LightBarrier::State state);

private:
    LightBarrier::State _state;
};

