#pragma once

enum PushButtonState
{
    PUSHBUTTON_PRESSED,
    PUSHBUTTON_RELEASED,
};

class PushButton
{
    public:
        PushButton(PushButtonState state) {_state =state;};
        PushButtonState get_state() const { return state_; };
        void set_state(PushButtonState state) { state_ = state; };
    private:
        PushButtonState state_;
};