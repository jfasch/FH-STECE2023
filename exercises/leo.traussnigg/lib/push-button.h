#pragma once

class PushButton {
public:
    
    enum State
    {
        PUSHBUTTON_PRESSED,
        PUSHBUTTON_RELEASED,
    };

    PushButton(State state) : state(state) {}

    State getState() {
        return state;
    }

    //for tests only
    void setState(State newState) {
        state = newState;
    }

private:
    State state;
};