#pragma once
#include "push-button.h"

class PushButton_Mock : public PushButton
{
public:

    PushButton_Mock(PushButton::State state);
    virtual PushButton::State get_state() const override;

    // for tests only
    virtual void set_state(PushButton::State state);

private:
    PushButton::State _state;
};
