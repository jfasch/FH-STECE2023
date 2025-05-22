#pragma once


enum PushButtonState
{
    PUSHBUTTON_PRESSED,
    PUSHBUTTON_RELEASED,
};

class PushButton
{
private:
    PushButtonState _state;

public:
    PushButton(PushButtonState state);
    PushButtonState get_state();

    // for test only
    void set_state(PushButtonState state);
};
