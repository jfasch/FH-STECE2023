#include <gtest/gtest.h>

#include <light-barrier.h>


TEST(lightbarrier_suite, init)
{
    {
        LightBarrier b(LightBarrier::State::BEAM_SOLID);
        ASSERT_EQ(b.get_state(), LightBarrier::State::BEAM_SOLID);
    }
    {
        LightBarrier b(LightBarrier::State::BEAM_BROKEN);
        ASSERT_EQ(b.get_state(), LightBarrier::State::BEAM_BROKEN);
    }
}

