#include <gtest/gtest.h>

#include <door/light-barrier-mock.h>


TEST(lightbarrier_suite, init)
{
    {
        LightBarrierMock b(LightBarrier::State::BEAM_SOLID);
        ASSERT_EQ(b.get_state(), LightBarrier::State::BEAM_SOLID);
    }
    {
        LightBarrierMock b(LightBarrier::State::BEAM_BROKEN);
        ASSERT_EQ(b.get_state(), LightBarrier::State::BEAM_BROKEN);
    }
}

