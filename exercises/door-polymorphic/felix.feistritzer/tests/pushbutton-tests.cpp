#include <gtest/gtest.h>

#include "push-button-mock.h"


TEST(pushbutton_suite, init)
{
    {
        MockPushButton b(PushButton::State::PRESSED);
        ASSERT_EQ(b.get_state(), PushButton::State::PRESSED);
    }
    {
        MockPushButton b(PushButton::State::RELEASED);
        ASSERT_EQ(b.get_state(), PushButton::State::RELEASED);
    }
}

