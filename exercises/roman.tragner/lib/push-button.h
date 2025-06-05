#pragma once


enum PushButtonState
{
    PUSHBUTTON_PRESSED,
    PUSHBUTTON_RELEASED,
};


class PushButton
{
public:
    //initialisieren
    PushButton(PushButtonState state);
    //state auslesen
    PushButtonState get_state();
    // state setzen //nur für tests
    void set_state(PushButtonState state);

private:
    //state ist privat und kann nur mit get_state() ausgelesen werden
    PushButtonState _state;
};