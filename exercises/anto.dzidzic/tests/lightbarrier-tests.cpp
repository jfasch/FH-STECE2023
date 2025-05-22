#include "light-barrier.h"
#include <gtest/gtest.h>

TEST(lightbarrier_suite, init)
{
    LightBarrier LightBarrier;

    LightBarrier.setState(LightBarrier::LIGHTBARRIER_BEAM_SOLID);
    ASSERT_EQ(LightBarrier.getState(), LightBarrier::LIGHTBARRIER_BEAM_SOLID);

    LightBarrier.setState(LightBarrier::LIGHTBARRIER_BEAM_BROKEN);
    ASSERT_EQ(LightBarrier.getState(), LightBarrier::LIGHTBARRIER_BEAM_BROKEN);
}

