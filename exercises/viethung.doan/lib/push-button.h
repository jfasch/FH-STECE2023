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
    // Konstruktor
    PushButton(PushButtonState state = PushButtonState::PUSHBUTTON_RELEASED);

    // Getter
    PushButtonState state() const;

    // Setter
    void set_state(PushButtonState state);
};
