#pragma once

class PushButton{

public:
 enum class PushButtonState{
    PUSHBUTTON_PRESSED,
    PUSHBUTTON_RELEASED,
    };

private:
PushButtonState state = PushButtonState::PUSHBUTTON_RELEASED;

public: 
  PushButton(PushButtonState initial_state) : state(initial_state) {}



PushButtonState get_state() const{
    return state;
}

void set_state(PushButtonState newstate){
    state = newstate;
}


};




