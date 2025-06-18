#pragma once


class ILightBarrier
{
public:
    enum State
        {
            BEAM_SOLID,
            BEAM_BROKEN,
        };

    virtual ~ILightBarrier() = default;
    virtual State get_state() const = 0;

    // for tests only
    virtual void set_state(State state) = 0;

};