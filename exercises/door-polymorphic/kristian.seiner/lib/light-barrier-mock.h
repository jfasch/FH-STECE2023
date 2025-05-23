#pragma once

#include "light-barrier.h"

class LightBarrierMock : public LightBarrier
{
public:

    LightBarrierMock(State state);
    State get_state() const;

    // for tests only
    void set_state(State state);

private:
    State _state;
};

