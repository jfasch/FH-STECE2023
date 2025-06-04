#pragma once

#include <push-button.h>

class PushButtonMock :  public PushButton
{
public:
    PushButtonMock(State state) : _state(state) {}
    State get_state() const override { return _state; }

    // Für Tests
    void set_state(State state) { _state = state; }


private:
    State _state;
};