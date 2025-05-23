#include <gtest/gtest.h>

#include <light-barrier.h>


TEST(lightbarrier_suite, init)
{
    {
        LightBarrier b(LightBarrier::State::BeamSolid);
        ASSERT_EQ(b.getState(), LightBarrier::State::BeamSolid);
    }
    {
        LightBarrier b(LightBarrier::State::BeamBroken);
        ASSERT_EQ(b.getState(), LightBarrier::State::BeamBroken);
    }
}

