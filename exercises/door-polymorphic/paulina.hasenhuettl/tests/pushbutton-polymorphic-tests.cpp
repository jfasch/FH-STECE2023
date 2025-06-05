#include "push-button-mock.h"
#include <gtest/gtest.h>

TEST(pushbutton_polymorphic_suite, base_conversion)
{
    PushButtonMock pb(PushButton::State::RELEASED);
    [[maybe_unused]] PushButton* base = &pb;
}

TEST(pushbutton_polymorphic_suite, access_through_base)
{
    PushButtonMock pb(PushButton::State::RELEASED);
    PushButton* base = &pb;

    PushButton::State state = base->get_state();
    ASSERT_EQ(state, PushButton::State::RELEASED);
}

TEST(pushbutton_polymorphic_suite, set_state)
{
    PushButtonMock pb(PushButton::State::RELEASED);
    [[maybe_unused]] PushButton* base = &pb;

    
    // base->set_state(PushButton::State::RELEASED);

    pb.set_state(PushButton::State::PRESSED);
}
