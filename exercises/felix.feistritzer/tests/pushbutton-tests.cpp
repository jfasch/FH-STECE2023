#include <gtest/gtest.h>

#include <push-button.h>


TEST(pushbutton_suite, init)
{
    {
        PushButton b(PushButtonState::PRESSED);
        ASSERT_EQ(b.get_state(), PushButtonState::PRESSED);
    }
    {
        PushButton b(PushButtonState::RELEASED);
        ASSERT_EQ(b.get_state(), PushButtonState::RELEASED);
    }
}

