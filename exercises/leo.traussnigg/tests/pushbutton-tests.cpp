#include <gtest/gtest.h>

#include <push-button.h>


TEST(pushbutton_suite, init)
{
    {
        PushButton b(PushButton::State::PUSHBUTTON_PRESSED);
        ASSERT_EQ(b.getState(), PushButton::State::PUSHBUTTON_PRESSED);
    }
    {
        PushButton b(PushButton::State::PUSHBUTTON_RELEASED);
        ASSERT_EQ(b.getState(), PushButton::State::PUSHBUTTON_RELEASED);
    }
}

