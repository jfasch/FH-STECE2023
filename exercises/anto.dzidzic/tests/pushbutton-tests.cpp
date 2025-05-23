#include <gtest/gtest.h>

#include <push-button.h>
//asdasd

TEST(pushbutton_suite, init)
{
    PushButton PushButton;
    
    PushButton.PushButton_set_state(PushButton::PUSHBUTTON_PRESSED);
    ASSERT_EQ(PushButton.PushButton_get_state(), PushButton::PUSHBUTTON_PRESSED);


    PushButton.PushButton_set_state(PushButton::PUSHBUTTON_RELEASED);
    ASSERT_EQ(PushButton.PushButton_get_state(), PushButton::PUSHBUTTON_RELEASED);

}

