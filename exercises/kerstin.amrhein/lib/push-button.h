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
    PushButton(PushButtonState init_state);
    PushButtonState get_state();

    // for tests only
    void set_state(PushButtonState state);
};



