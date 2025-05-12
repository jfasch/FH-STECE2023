#pragma once

enum LightBarrierState
{
    BEAM_SOLID,
    BEAM_BROKEN,
};

struct  LightBarrier
{
    LightBarrierState state;
};

/*    
public:
    LightBarrier(LightBarrierState initialState) : state(initialState) {}

    LightBarrierState getState() const { return state; }
    void setState(LightBarrierState newState) { state = newState; }

private:
    LightBarrierState state;
};
*/