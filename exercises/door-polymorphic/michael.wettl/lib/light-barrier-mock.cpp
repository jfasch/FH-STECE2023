#include "light-barrier.h"
#include "light-barrier-mock.h"


LightBarrier_Mock::LightBarrier_Mock(State state)
{
    _state = state;
}

LightBarrier_Mock::State LightBarrier_Mock::get_state() const
{
    return _state;
}

void LightBarrier_Mock::set_state(State state)
{
    _state = state;
}
