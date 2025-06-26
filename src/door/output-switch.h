#pragma once

class OutputSwitch
{
public:
    enum class State
    {
        OUTPUT_LOW,
        OUTPUT_HIGH,
    };

    virtual ~OutputSwitch() = default;
    virtual void set_state(State state) = 0;
};

