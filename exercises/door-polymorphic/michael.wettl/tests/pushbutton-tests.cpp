#include <gtest/gtest.h>

#include <push-button-mock.h>


TEST(pushbutton_suite, init)
{
    {
        PushButton_Mock b(PushButton::State::PRESSED);
        ASSERT_EQ(b.get_state(), PushButton::State::PRESSED);
    }
    {
        PushButton_Mock b(PushButton::State::RELEASED);
        ASSERT_EQ(b.get_state(), PushButton::State::RELEASED);
    }
}

