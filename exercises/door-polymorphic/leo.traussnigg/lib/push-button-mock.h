#pragma once

#include "push-button.h"

class PushButtonMock : public PushButton
{
public:
    PushButtonMock(PushButton::State state);
    PushButton::State get_state() const;

    // for tests only
    void set_state(PushButton::State state);

private:
    PushButton::State _state;
};
