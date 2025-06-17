#pragma once

class LightBarrier
{
public:
    enum class State
    {
        BEAM_SOLID,
        BEAM_BROKEN,
    };

    virtual ~LightBarrier() = default;                    // <-- virtual destructor
    virtual State get_state() const = 0;                  // <-- pure virtual method
};