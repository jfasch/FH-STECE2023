#pragma once

class LightBarrier
{
public:
    enum class State
    {
        BEAM_SOLID,
        BEAM_BROKEN,
    };

    LightBarrier(State initialState = State::BEAM_SOLID);
    
    State getState() const;
    void setState(State state); 

private:
    State state;
};