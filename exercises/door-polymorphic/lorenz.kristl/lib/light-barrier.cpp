#include "light-barrier.h"


LightBarrier::LightBarrier(State state)
{
    _state = state;
}

LightBarrier::State LightBarrier::get_state() const
{
    return _state;
}

void LightBarrier::set_state(State state)
{
    _state = state;
}
