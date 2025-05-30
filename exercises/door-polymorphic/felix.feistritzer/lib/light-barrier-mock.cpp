#include "light-barrier-mock.h"


MockLightBarrier::MockLightBarrier(LightBarrier::State state)
{
    _state = state;
}

MockLightBarrier::LightBarrier::State MockLightBarrier::get_state() const
{
    return _state;
}

void MockLightBarrier::set_state(LightBarrier::State state)
{
    _state = state;
}
