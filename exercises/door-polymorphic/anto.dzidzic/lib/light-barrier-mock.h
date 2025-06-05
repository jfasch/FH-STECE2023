#pragma once
#include "light-barrier.h"

class LightBarrierMock : public ILightBarrier
{
public:

    explicit LightBarrierMock(State state);
    State get_state() const override;

    // for tests only
    void set_state(State state) override ;

private:
    State _state;
};

