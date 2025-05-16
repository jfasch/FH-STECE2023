#pragma once


enum PushButtonState
{
    PUSHBUTTON_PRESSED,
    PUSHBUTTON_RELEASED,
};


class PushButton
{
private:
    PushButtonState state;
public:
    PushButton(PushButtonState state = PUSHBUTTON_RELEASED)
    :state(state) {}

    PushButtonState PushButton_get_state() const
    {
        return state;
    }

    void PushButton_set_state(PushButtonState new_state)
    {
        state = new_state;
    }
};

