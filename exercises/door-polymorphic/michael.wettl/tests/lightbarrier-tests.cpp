#include <gtest/gtest.h>

#include <light-barrier-mock.h>


TEST(lightbarrier_suite, init)
{
    {
        LightBarrier_Mock b(LightBarrier::State::BEAM_SOLID);
        ASSERT_EQ(b.get_state(), LightBarrier::State::BEAM_SOLID);
    }
    {
        LightBarrier_Mock b(LightBarrier::State::BEAM_BROKEN);
        ASSERT_EQ(b.get_state(), LightBarrier::State::BEAM_BROKEN);
    }
}

