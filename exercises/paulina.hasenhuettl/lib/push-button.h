#pragma once

enum class PushButtonState
{
    PRESSED,
    RELEASED,
};

class PushButton
{
public:
    PushButton(PushButtonState state);

    PushButtonState get_state() const;
    void set_state(PushButtonState state); // for tests only

private:
    PushButtonState _state;
};


/*
#pragma once


enum PushButtonState
{
    PUSHBUTTON_PRESSED,
    PUSHBUTTON_RELEASED,
};

struct PushButton
{
    PushButtonState state;
};

void PushButton_init(PushButton* self, PushButtonState state);
PushButtonState PushButton_get_state(PushButton* self);

// for tests only
void PushButton_set_state(PushButton* self, PushButtonState state);
*/