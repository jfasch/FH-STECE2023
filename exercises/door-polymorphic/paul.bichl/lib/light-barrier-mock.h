#pragma once

#include "light-barrier.h"

class MockLightBarrier : public LightBarrier
{
public:
    MockLightBarrier(State state) : _state(state) {}
    
    virtual State get_state() const override;
    virtual void set_state(State state) override;

private:
    State _state;
};

