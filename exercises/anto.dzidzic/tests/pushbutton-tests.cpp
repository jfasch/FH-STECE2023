#include <gtest/gtest.h>

#include <push-button.h>


TEST(pushbutton_suite, init)
{
    PushButton PushButton;
    
    PushButton.PushButton_set_state(PUSHBUTTON_PRESSED);
    ASSERT_EQ(PushButton.PushButton_get_state(), PUSHBUTTON_PRESSED);


    PushButton.PushButton_set_state(PUSHBUTTON_RELEASED);
    ASSERT_EQ(PushButton.PushButton_get_state(), PUSHBUTTON_RELEASED);

}

