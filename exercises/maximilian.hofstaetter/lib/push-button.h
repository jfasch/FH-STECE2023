#pragma once

enum PushButtonState
{
    PUSHBUTTON_PRESSED,
    PUSHBUTTON_RELEASED,
};

class PushButton{

    private:
        PushButtonState _state;

    public:

    ~PushButton();
    PushButton(PushButtonState state);
    void PushButton_set_state(PushButtonState state);
    PushButtonState PushButton_get_state() const;
};