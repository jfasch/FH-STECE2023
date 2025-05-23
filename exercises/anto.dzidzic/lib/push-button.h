#pragma once
//dasdada


class PushButton
{
    public:
        enum PushButtonState
    {
        PUSHBUTTON_PRESSED,
        PUSHBUTTON_RELEASED,
    };

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
    private:
        PushButtonState state;
};

