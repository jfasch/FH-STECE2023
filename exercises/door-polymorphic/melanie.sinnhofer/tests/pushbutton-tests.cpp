#include <gtest/gtest.h>

#include <push-button.h>
#include <push-button-mock.h>


TEST(pushbutton_suite, init)
{
    {
        PushButtonMock b(PushButtonMock::State::PRESSED);
        ASSERT_EQ(b.get_state(), PushButton::State::PRESSED);
    }
    {
        PushButtonMock b(PushButtonMock::State::RELEASED);
        ASSERT_EQ(b.get_state(), PushButton::State::RELEASED);
    }
}

