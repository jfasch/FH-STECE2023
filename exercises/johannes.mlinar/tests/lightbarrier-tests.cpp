#include <gtest/gtest.h>
#include "light-barrier.h"

TEST(LightBarrierTestSuite, init)
{
    {
        LightBarrier b(LightBarrierState::BEAM_SOLID);
        ASSERT_EQ(b.getState(), LightBarrierState::BEAM_SOLID);
    }
    {
        LightBarrier b(LightBarrierState::BEAM_BROKEN);
        ASSERT_EQ(b.getState(), LightBarrierState::BEAM_BROKEN);
    }
}
