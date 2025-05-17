// push-button.hpp
#pragma once

// Beibehalten der ursprünglichen Enum-Namen
enum PushButtonState { //enum class machen dann geht PushButtonState::PRESSED
    PUSHBUTTON_PRESSED,
    PUSHBUTTON_RELEASED,
};

// PushButton-Klasse mit identischem Member-Namen "state"
class PushButton {
public:
    // Initialisierung (intern)
    PushButton(PushButtonState state);
    
     // Rückgabe des aktuellen Zustands (intern)
     PushButtonState get_state();
    
    //test only
    void set_state(PushButtonState state);

private:
    // Beibehaltung des Member-Namens
    PushButtonState _state;
};


