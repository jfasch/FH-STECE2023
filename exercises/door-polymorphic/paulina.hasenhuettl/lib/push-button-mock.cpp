#include "push-button-mock.h"

PushButtonMock::PushButtonMock(State state)
    : _state(state)
{}

PushButton::State PushButtonMock::get_state() const {
    return _state;
}

void PushButtonMock::set_state(State state) {
    _state = state;
}
