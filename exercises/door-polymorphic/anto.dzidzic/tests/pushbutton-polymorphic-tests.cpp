#include <push-button-mock.h>

#include <gtest/gtest.h>


TEST(pushbutton_polymorphic_suite, base_conversion)
{
    PushButtonMock pb(IPushButton::State::RELEASED);
    [[maybe_unused]] IPushButton* base = &pb;           // <-- derived converted to base
}

TEST(pushbutton_polymorphic_suite, access_through_base)
{
    PushButtonMock pb(IPushButton::State::RELEASED);
    IPushButton* base = &pb;

    IPushButton::State state = base->get_state();      // <-- through base, derived's get_state() is called

    ASSERT_EQ(state, IPushButton::State::RELEASED);
}

TEST(pushbutton_polymorphic_suite, set_state)
{
    PushButtonMock pb(IPushButton::State::RELEASED);
    [[maybe_unused]] IPushButton* base = &pb;

    // ***this must not compile***
    // base->set_state(PushButton::State::RELEASED);

    pb.set_state(IPushButton::State::PRESSED);
}
