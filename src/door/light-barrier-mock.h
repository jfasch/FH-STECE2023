#pragma once

#include "light-barrier.h"

class LightBarrierMock : public LightBarrier
{
public:
    LightBarrierMock(State state);
    virtual State get_state() const override;

    // for tests only (puropsely not part of the interface)
    void set_state(State state);

private:
    State _state;
};

