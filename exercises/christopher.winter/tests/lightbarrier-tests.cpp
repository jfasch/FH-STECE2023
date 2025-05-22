#include <gtest/gtest.h>

#include <light-barrier.h>


TEST(lightbarrier_suite, init)
{
    {
        LightBarrier b(LIGHTBARRIER_BEAM_SOLID);

        //LightBarrier_init(&b, LIGHTBARRIER_BEAM_SOLID);
        ASSERT_EQ(b.LightBarrier_get_state(), LIGHTBARRIER_BEAM_SOLID);
    }
    {
        LightBarrier b(LIGHTBARRIER_BEAM_BROKEN);
        //LightBarrier_init(&b, LIGHTBARRIER_BEAM_BROKEN);
        ASSERT_EQ(b.LightBarrier_get_state(), LIGHTBARRIER_BEAM_BROKEN);
    }
}

