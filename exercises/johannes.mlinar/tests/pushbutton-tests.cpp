#include <gtest/gtest.h>
#include "push-button.h"

TEST(PushButtonTestSuite, init)
{
    {
        PushButton b(PushButtonState::PRESSED);
        ASSERT_EQ(b.getState(), PushButtonState::PRESSED);
    }
    {
        PushButton b(PushButtonState::RELEASED);
        ASSERT_EQ(b.getState(), PushButtonState::RELEASED);
    }
}
