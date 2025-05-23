#pragma once
#include "light-barrier.h"

class LightBarrierMock : public LightBarrier
{
public:


    LightBarrierMock(LightBarrier::State state);
    LightBarrier::State get_state() const override;

    // for tests only
     void set_state(LightBarrier::State state) override;

private:
    LightBarrier::State _state;
};

