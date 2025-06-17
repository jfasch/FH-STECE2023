#pragma once

#include <light-barrier.h>

class LightBarrierMock : public LightBarrier
{
public:

    LightBarrierMock(State state) : _state(state) {};
    State get_state() const override { return _state; }

    // for tests only
    void set_state(State state) { _state = state; }

private:
    State _state;
};