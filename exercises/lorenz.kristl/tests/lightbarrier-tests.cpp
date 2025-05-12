/*
#include <gtest/gtest.h>
#include <light-barrier.h>


TEST(lightbarrier_suite, init)
{
    {
        LightBarrier b;
        LightBarrier_init(&b, LIGHTBARRIER_BEAM_SOLID);
        ASSERT_EQ(LightBarrier_get_state(&b), LIGHTBARRIER_BEAM_SOLID);
    }
    {
        LightBarrier b;
        LightBarrier_init(&b, LIGHTBARRIER_BEAM_BROKEN);
        ASSERT_EQ(LightBarrier_get_state(&b), LIGHTBARRIER_BEAM_BROKEN);
    }
}
*/
#include <gtest/gtest.h>
#include <light-barrier.h>

TEST(lightbarrier_suite, init)
{
    {
        // Initialize light barrier with BEAM_SOLID state
        LightBarrier b(LightBarrier::State::BEAM_SOLID);
        ASSERT_EQ(b.getState(), LightBarrier::State::BEAM_SOLID);
    }
    {
        // Initialize light barrier with BEAM_BROKEN state
        LightBarrier b(LightBarrier::State::BEAM_BROKEN);
        ASSERT_EQ(b.getState(), LightBarrier::State::BEAM_BROKEN);
    }
}