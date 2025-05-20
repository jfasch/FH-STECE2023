#pragma once
#include <push-button.h>

class PushButtonMock : public PushButton
{
    private:
    PushButtonState _state;

    public:
    PushButtonMock(PushButtonState state) {_state = state;};
    PushButtonState get_state() const {return _state;};
    void set_state(PushButtonState state) {_state = state;};
};
