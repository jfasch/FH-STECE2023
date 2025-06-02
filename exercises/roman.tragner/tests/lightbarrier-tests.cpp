#include <gtest/gtest.h>

#include <light-barrier.h>


TEST(lightbarrier_suite, init)
{
    {
        LightBarrier b(BEAM_SOLID);
        ASSERT_EQ(b.get_state(), BEAM_SOLID);
    }
    {
        LightBarrier b(BEAM_BROKEN);
        ASSERT_EQ(b.get_state(), BEAM_BROKEN);
    }
}

