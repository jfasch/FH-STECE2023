// push-button.cpp
#include "push-button.h"

// Initialisiert den Button-Zustand
PushButton::PushButton(PushButtonState state) {
    _state = state;
}

// Liefert den aktuellen Zustand zurück
PushButtonState PushButton::get_state()  {
    return _state;
}

// Setzt den Zustand (z. B. für Unit-Tests)
void PushButton::set_state(PushButtonState state) {
    _state = state;
}


