#include <gtest/gtest.h>

#include <push-button.h>


TEST(pushbutton_suite, init)
{
    {
        PushButton b(PushButton::PushButtonState::PUSHBUTTON_PRESSED);
        ASSERT_EQ(b.get_state(), PushButton::PushButtonState::PUSHBUTTON_PRESSED);
    }
    {
        PushButton b(PushButton::PushButtonState::PUSHBUTTON_RELEASED);
        ASSERT_EQ(b.get_state(), PushButton::PushButtonState::PUSHBUTTON_RELEASED);
    }
}

