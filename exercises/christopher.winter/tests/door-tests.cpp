#include <gtest/gtest.h>

#include <door.h>


TEST(door_suite, straightforward_open)
{
    // build a door and its parts
    Motor motor(MOTOR_IDLE);
    //Motor_init(&motor, MOTOR_IDLE);

    PushButton do_close(PUSHBUTTON_RELEASED);
    //do_clode.PushButton(PUSHBUTTON_RELEASED);

    PushButton do_open(PUSHBUTTON_RELEASED);
    //do_open.PushButton(PUSHBUTTON_RELEASED);

    LightBarrier closed_position(LIGHTBARRIER_BEAM_BROKEN);
    //LightBarrier_init(&closed_position, LIGHTBARRIER_BEAM_BROKEN);  // <-- door in "closed" position

    LightBarrier opened_position(LIGHTBARRIER_BEAM_SOLID);
    //LightBarrier_init(&opened_position, LIGHTBARRIER_BEAM_SOLID);   // <-- door not in "opened" position

    Door door(&motor, &do_close, &do_open, &closed_position, &opened_position);
    //Door_init(&door, &motor, &do_close, &do_open, &closed_position, &opened_position);

    door.Door_check();
    ASSERT_EQ(door.State_Get(), DOOR_CLOSED);                // <-- inferred from the light barrier situation

    // all idle: no button pressed -> motor must remain idle at
    // check()
    door.Door_check();
    ASSERT_EQ(motor.Motor_get_direction(), MOTOR_IDLE);

    // "open" button pressed -> motor direction must be set to
    // "opening"
    
    //PushButton_set_state(&do_open, PUSHBUTTON_PRESSED);
    do_open.setState(PUSHBUTTON_PRESSED);
    assert(do_open.getState() == PUSHBUTTON_PRESSED);

    door.Door_check();    
    ASSERT_EQ(motor.Motor_get_direction(), MOTOR_FORWARD);

    // "opened" position reached (light barrier's beam broken) ->
    // motor stopped
    opened_position.LightBarrier_set_state(LIGHTBARRIER_BEAM_BROKEN);
    closed_position.LightBarrier_set_state(LIGHTBARRIER_BEAM_SOLID);
    //LightBarrier_set_state(&opened_position, LIGHTBARRIER_BEAM_BROKEN);
    //LightBarrier_set_state(&closed_position, LIGHTBARRIER_BEAM_SOLID);    // <-- should probably be verified by door logic: 
                                                                          //     if one beam is broken, the other must be solid, 
                                                                          //     and vice versa
    door.Door_check();
    ASSERT_EQ(motor.Motor_get_direction(), MOTOR_IDLE);
}
