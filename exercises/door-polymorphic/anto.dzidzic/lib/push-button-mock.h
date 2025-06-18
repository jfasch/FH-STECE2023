#pragma once
#include "push-button.h"

class PushButtonMock : public IPushButton
{
public:

    explicit PushButtonMock (State state);
    State get_state() const override;

    // for tests only
    void set_state(State state) override;

private:
    State _state;
};
