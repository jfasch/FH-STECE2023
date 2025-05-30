#include <gtest/gtest.h>

#include <push-button.h>


TEST(pushbutton_suite, init)
{
    {
        PushButton b(PUSHBUTTON_PRESSED);
        ASSERT_EQ(b.state(), PUSHBUTTON_PRESSED);
    }

    {
        PushButton b(PUSHBUTTON_RELEASED);
        ASSERT_EQ(b.state(), PUSHBUTTON_RELEASED);
    }
}

