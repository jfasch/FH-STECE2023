#include <push-button-mock.h>

#include <gtest/gtest.h>


TEST(pushbutton_polymorphic_suite, base_conversion)
{
    PushButton_Mock pb(PushButton::State::RELEASED);
    [[maybe_unused]] PushButton* base = &pb;           // <-- derived converted to base
}

TEST(pushbutton_polymorphic_suite, access_through_base)
{
    PushButton_Mock pb(PushButton::State::RELEASED);
    PushButton* base = &pb;

    PushButton::State state = base->get_state();      // <-- through base, derived's get_state() is called

    ASSERT_EQ(state, PushButton::State::RELEASED);
}

TEST(pushbutton_polymorphic_suite, set_state)
{
    PushButton_Mock pb(PushButton::State::RELEASED);
    [[maybe_unused]] PushButton* base = &pb;

    // ***this must not compile***
    // base->set_state(PushButton::State::RELEASED);

    pb.set_state(PushButton::State::PRESSED);
}
