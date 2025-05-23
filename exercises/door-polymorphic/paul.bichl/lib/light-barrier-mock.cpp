#include "light-barrier-mock.h"

LightBarrier::State MockLightBarrier::get_state() const
{
    return _state;
}

void MockLightBarrier::set_state(LightBarrier::State state)
{
    _state = state;
}
