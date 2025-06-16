#include <gtest/gtest.h>

#include <push-button.h>


TEST(pushbutton_suite, init)
{
    {
        PushButton b(PushButton::State::PRESSED);
        ASSERT_EQ(b.get_state(), PushButton::State::PRESSED);
    }
    {
        PushButton b(PushButton::State::RELEASED);
        ASSERT_EQ(b.get_state(), PushButton::State::RELEASED);
    }
}

