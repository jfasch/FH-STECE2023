#pragma once
#include "light-barrier.h"

class LightBarrier_Mock : public LightBarrier
{
public:

    LightBarrier_Mock(LightBarrier::State state);
    virtual LightBarrier::State get_state() const override;

    // for tests only
    virtual void set_state(LightBarrier::State state) override;

private:
    LightBarrier::State _state;
};

