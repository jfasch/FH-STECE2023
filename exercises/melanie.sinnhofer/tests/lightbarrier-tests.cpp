#include <gtest/gtest.h>

#include <light-barrier.h>


TEST(lightbarrier_suite, init)
{
    {
        LightBarrier lb(LightBarrier::State::BEAM_SOLID);
        ASSERT_EQ(lb.get_state(), LightBarrier::State::BEAM_SOLID);
    }
    {
        LightBarrier lb(LightBarrier::State::BEAM_BROKEN);
        ASSERT_EQ(lb.get_state(), LightBarrier::State::BEAM_BROKEN);    }
}

