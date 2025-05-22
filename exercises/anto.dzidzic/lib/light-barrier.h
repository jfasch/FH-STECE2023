#pragma once



class LightBarrier
{   
public:
    enum State
    {
        LIGHTBARRIER_BEAM_SOLID,
        LIGHTBARRIER_BEAM_BROKEN,
    };

    LightBarrier(State initialState = LIGHTBARRIER_BEAM_BROKEN)
    : state(initialState) {}


    State getState() const {
        return state;
    }

    void setState(State newState) {
        state = newState;
    }

    private:
        State state;
    //asdasda
};
