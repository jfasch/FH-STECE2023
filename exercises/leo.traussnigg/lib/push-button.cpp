#include "push-button.h"

enum class PushButtonState {
    PUSHBUTTON_PRESSED,
    PUSHBUTTON_RELEASED
};

class PushButton {
public:
    PushButton(PushButtonState state) : state(state) {}

    PushButtonState getState() const {
        return state;
    }

    //for tests only
    void setState(PushButtonState newState) {
        state = newState;
    }

private:
    PushButtonState state;
};
