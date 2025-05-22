#include <gtest/gtest.h>
#include "push-button.h"

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


/*
#include <gtest/gtest.h>

#include <push-button.h>


TEST(pushbutton_suite, init)
{
    {
        PushButton b;
        PushButton_init(&b, PUSHBUTTON_PRESSED);
        ASSERT_EQ(PushButton_get_state(&b), PUSHBUTTON_PRESSED);
    }
    {
        PushButton b;
        PushButton_init(&b, PUSHBUTTON_RELEASED);
        ASSERT_EQ(PushButton_get_state(&b), PUSHBUTTON_RELEASED);
    }
}
*/
