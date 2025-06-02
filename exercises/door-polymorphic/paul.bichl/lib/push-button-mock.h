#pragma once

#include "push-button.h"

class MockPushButton : public PushButton
{
public:
    MockPushButton(State state) : _state(state) {}

    virtual State get_state() const override;
    virtual void set_state(State state) override;

private:
    State _state;
};

