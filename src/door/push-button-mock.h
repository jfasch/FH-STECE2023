#pragma once

#include "push-button.h"


class PushButtonMock : public PushButton
{
public:
    PushButtonMock(State state);
    State get_state() const override;

    // for tests only (purposely not part of the interface)
    void set_state(State state);

private:
    State _state;
};
