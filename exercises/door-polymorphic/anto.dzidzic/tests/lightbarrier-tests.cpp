#include <gtest/gtest.h>

#include <light-barrier-mock.h>


TEST(lightbarrier_suite, init)
{
    {
        LightBarrierMock b(ILightBarrier::State::BEAM_SOLID);
        ASSERT_EQ(b.get_state(), ILightBarrier::State::BEAM_SOLID);
    }
    {
        LightBarrierMock b(ILightBarrier::State::BEAM_BROKEN);
        ASSERT_EQ(b.get_state(), ILightBarrier::State::BEAM_BROKEN);
    }
}

