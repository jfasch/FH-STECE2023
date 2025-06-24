#pragma once

class InputSwitch
{
public:
    enum class State
    {
        INPUT_FALSE,
        INPUT_TRUE,
    };

    virtual ~InputSwitch() = default;
    virtual State get_state() = 0;
};

