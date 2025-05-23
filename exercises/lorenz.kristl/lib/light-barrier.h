/*
#pragma once

enum LightBarrierState
{
    LIGHTBARRIER_BEAM_SOLID,
    LIGHTBARRIER_BEAM_BROKEN,
};

struct LightBarrier
{
    LightBarrierState state;
};

void LightBarrier_init(LightBarrier* self, LightBarrierState state);
LightBarrierState LightBarrier_get_state(LightBarrier* self);

// for tests only
void LightBarrier_set_state(LightBarrier* self, LightBarrierState state);
*/
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
