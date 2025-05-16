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
    PushButton(PushButtonState state);
    PushButtonState get_state() const;
    
    //For Tests only
    void set_state(PushButtonState state);

};


/*
void PushButton_init(PushButton* self, PushButtonState state);
PushButtonState PushButton_get_state(PushButton* self);

// for tests only
void PushButton_set_state(PushButton* self, PushButtonState state);*/
