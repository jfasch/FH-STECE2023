#pragma once

enum class PushButtonState {
    PRESSED,
    RELEASED
};

class PushButton {
public:
    PushButton(PushButtonState state = PushButtonState::RELEASED) : state(state) {}

    PushButtonState getState() const { return state; }
    void setState(PushButtonState newState) { state = newState; }

private:
    PushButtonState state;
};
