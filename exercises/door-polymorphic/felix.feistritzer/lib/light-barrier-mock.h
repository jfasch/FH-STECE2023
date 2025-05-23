#pragma once

#include "light-barrier.h"

class MockLightBarrier : public LightBarrier
{
public:
    MockLightBarrier(LightBarrier::State state);
    LightBarrier::State get_state() const;

    // for tests only
    void set_state(LightBarrier::State state);

private:
    LightBarrier::State _state;
};

