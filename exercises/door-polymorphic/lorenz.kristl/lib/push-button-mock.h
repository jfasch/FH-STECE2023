#pragma once
#include <push-button.h>

class PushButtonMock : public PushButton
{
public:

    PushButtonMock(State state);
    State get_state() const override;
    // for tests only
    void set_state(State state) override;

private:
    State _state;
};
