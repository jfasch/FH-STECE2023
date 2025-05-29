#pragma once
#include <push-button.h>

class PushButtonMock : public PushButton
{
    private:
    PushButton::State _state;

    public:
    PushButtonMock(PushButton::State state) {_state = state;};
    PushButton::State get_state() const {return _state;};
    void set_state(PushButton::State state) {_state = state;};
};
