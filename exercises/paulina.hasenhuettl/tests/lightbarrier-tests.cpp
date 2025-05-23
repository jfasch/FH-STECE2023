#include <gtest/gtest.h>
#include "light-barrier.h"

TEST(lightbarrier_suite, init)
{
    {
        LightBarrier b(LightBarrierState::BEAM_SOLID);
        ASSERT_EQ(b.get_state(), LightBarrierState::BEAM_SOLID);
    }
    {
        LightBarrier b(LightBarrierState::BEAM_BROKEN);
        ASSERT_EQ(b.get_state(), LightBarrierState::BEAM_BROKEN);
    }
}

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
