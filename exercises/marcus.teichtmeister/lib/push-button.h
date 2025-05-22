#pragma once

enum PushButtonState
{
    PUSHBUTTON_PRESSED,
    PUSHBUTTON_RELEASED,
};

class PushButton
{
    public:
    virtual PushButtonState get_state() const = 0;
    virtual void set_state(PushButtonState state) = 0;
};