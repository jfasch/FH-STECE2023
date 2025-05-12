#pragma once


enum PushButtonState
{
    PUSHBUTTON_PRESSED,
    PUSHBUTTON_RELEASED,
};

class PushButton
{
public:
    PushButton(PushButtonState state);
    PushButtonState get_state();
    // for tests only
    void set_state(PushButtonState state);

private:
    PushButtonState _state;
};