#include <gtest/gtest.h>

#include <push-button.h>


TEST(pushbutton_suite, init)
{
    {
        PushButton b(PushButtonState::PUSHBUTTON_PRESSED);
        ASSERT_EQ(b.get_state(), PushButtonState::PUSHBUTTON_PRESSED);
    }
    {
        PushButton b(PushButtonState::PUSHBUTTON_RELEASED);
        ASSERT_EQ(b.get_state(), PushButtonState::PUSHBUTTON_RELEASED);
    }
}

