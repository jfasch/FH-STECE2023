#include <gtest/gtest.h>

#include <push-button-mock.h>


TEST(pushbutton_suite, init)
{
    {
        PushButtonMock b(IPushButton::State::PRESSED);
        ASSERT_EQ(b.get_state(), IPushButton::State::PRESSED);
    }
    {
        PushButtonMock b(IPushButton::State::RELEASED);
        ASSERT_EQ(b.get_state(), IPushButton::State::RELEASED);
    }
}

