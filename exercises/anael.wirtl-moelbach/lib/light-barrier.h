#pragma once


class LightBarrier{

public:
enum class LightBarrierState{
    LIGHTBARRIER_BEAM_SOLID,
    LIGHTBARRIER_BEAM_BROKEN,
};

private:
    LightBarrierState state;

public:

LightBarrier(LightBarrierState initState = LightBarrierState::LIGHTBARRIER_BEAM_SOLID)
    :state(initState) {}

LightBarrierState get_state() const{
    return state;
}


// for tests only
void set_state(LightBarrierState newstate){
    state = newstate;
}

};

