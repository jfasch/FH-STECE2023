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
    void set_State(PushButtonState state);
    ~PushButton();
    PushButtonState get_state(){return this->_state;}
};
