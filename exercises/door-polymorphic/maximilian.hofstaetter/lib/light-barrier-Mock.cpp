#include "light-barrier-Mock.h"


LightBarrierMock::LightBarrierMock(State state)
{
    _state = state;
}

LightBarrierMock::State LightBarrierMock::get_state() const
{
    return _state;
}

void LightBarrierMock::set_state(State state)
{
    _state = state;
}
