#include <light-barrier-mock.h>

#include <gtest/gtest.h>


TEST(lightbarrier_polymorphic_suite, base_conversion)
{
    LightBarrierMock lb(ILightBarrier::State::BEAM_SOLID);
    [[maybe_unused]] ILightBarrier* base = &lb;         // <-- derived converted to base
}

TEST(lightbarrier_polymorphic_suite, access_through_base)
{
    LightBarrierMock lb(ILightBarrier::State::BEAM_SOLID);
    ILightBarrier* base = &lb;

    ILightBarrier::State state = base->get_state();      // <-- through base, derived's get_state() is called

    ASSERT_EQ(state, ILightBarrier::State::BEAM_SOLID);
}

TEST(lightbarrier_polymorphic_suite, set_state)
{
    LightBarrierMock lb(ILightBarrier::State::BEAM_SOLID);
    [[maybe_unused]] ILightBarrier* base = &lb;

    // ***this must not compile***
    // base->set_state(LightBarrier::State::BEAM_SOLID);

    lb.set_state(ILightBarrier::State::BEAM_SOLID);
}
