#include <gtest/gtest.h>

#include <light-barrier.h>


TEST(lightbarrier_suite, init)
{
    {
        LightBarrier b(LightBarrier::LightBarrierState::LIGHTBARRIER_BEAM_SOLID);
        ASSERT_EQ(b.get_state(), LightBarrier::LightBarrierState::LIGHTBARRIER_BEAM_SOLID);
    }
    {
        LightBarrier b(LightBarrier::LightBarrierState::LIGHTBARRIER_BEAM_BROKEN);
        ASSERT_EQ(b.get_state(), LightBarrier::LightBarrierState::LIGHTBARRIER_BEAM_BROKEN);
    }
}

