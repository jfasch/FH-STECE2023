#pragma once

enum class PushButtonState
{
    PRESSED,
    RELEASED,
};

class PushButton
{
    private:
        PushButtonState _state;

    public:
        PushButton(PushButtonState state);

        PushButtonState get_state() const { return _state; };

        // for tests only
        void set_state(PushButtonState state) { _state = state; };
};