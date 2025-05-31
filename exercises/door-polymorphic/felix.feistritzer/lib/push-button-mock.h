#pragma once

#include "push-button.h"

class MockPushButton : public PushButton
{
public:
    MockPushButton(PushButton::State state);
    PushButton::State get_state() const override;

    // for tests only
    void set_state(PushButton::State state) override;

private:
    PushButton::State _state;
};
