#include <gtest/gtest.h>

#include <door.h>


TEST(door_suite, straightforward_open)
{
    Motor motor = Motor(Motor::BACKWARD);
    PushButton do_close = PushButton(PushButton::PUSHBUTTON_RELEASED);
    PushButton do_open = PushButton(PushButton::PUSHBUTTON_RELEASED);
    LightBarrier closed_position = LightBarrier(LightBarrier::LIGHTBARRIER_BEAM_BROKEN);
    LightBarrier opened_position= LightBarrier(LightBarrier::LIGHTBARRIER_BEAM_SOLID);
    Door door = Door(&motor, &do_close, &do_open, &closed_position, &opened_position);


    Door_check(&door);
    ASSERT_EQ(door.state, DOOR_CLOSED);                // <-- inferred from the light barrier situation

    // all idle: no button pressed -> motor must remain idle at
    // check()
    Door_check(&door);
    ASSERT_EQ(Motor_get_direction(&motor), MOTOR_IDLE);

    // "open" button pressed -> motor direction must be set to
    // "opening"
    PushButton_set_state(&do_open, PUSHBUTTON_PRESSED);
    Door_check(&door);    
    ASSERT_EQ(Motor_get_direction(&motor), MOTOR_FORWARD);

    // "opened" position reached (light barrier's beam broken) ->
    // motor stopped
    LightBarrier_set_state(&opened_position, LIGHTBARRIER_BEAM_BROKEN);
    LightBarrier_set_state(&closed_position, LIGHTBARRIER_BEAM_SOLID);    // <-- should probably be verified by door logic: 
                                                                          //     if one beam is broken, the other must be solid, 
                                                                          //     and vice versa
    Door_check(&door);
    ASSERT_EQ(Motor_get_direction(&motor), MOTOR_IDLE);
}
