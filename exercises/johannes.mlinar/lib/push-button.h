#pragma once

class PushButton{
    public:
    enum PushButtonState
    {
    PUSHBUTTON_PRESSED,
    PUSHBUTTON_RELEASED,
    };
    PushButtonState PushButton_get_state();
    PushButton(PushButtonState state){
        _state=state;
    }
    // for tests only
    void PushButton_set_state(PushButtonState state);
    
    private:
    PushButtonState _state;
};   

