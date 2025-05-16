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

#include <gtest/gtest.h>
#include <push-button.h>

TEST(pushbutton_suite, init)
{
    {
        // Initialize push button with PRESSED state
        PushButton b(PushButton::State::PRESSED);
        ASSERT_EQ(b.getState(), PushButton::State::PRESSED);
    }
    {
        // Initialize push button with RELEASED state
        PushButton b(PushButton::State::RELEASED);
        ASSERT_EQ(b.getState(), PushButton::State::RELEASED);
    }
}