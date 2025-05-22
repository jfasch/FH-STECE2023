#include <gtest/gtest.h>

#include <door.h>


TEST(door_suite, straightforward_open)
{
    // build a door and its parts
    Motor motor(MOTOR_IDLE);

    PushButton do_close(PUSHBUTTON_RELEASED);
    PushButton do_open(PUSHBUTTON_RELEASED);

    LightBarrier closed_position(LIGHTBARRIER_BEAM_BROKEN);  // <-- door in "closed" position
    LightBarrier opened_position(LIGHTBARRIER_BEAM_SOLID);    // <-- door not in "opened" position


    Door door(&motor, &do_close, &do_open, &closed_position, &opened_position);

    door.check();
    ASSERT_EQ(door.state(), DOOR_CLOSED);                // <-- inferred from the light barrier situation

    // all idle: no button pressed -> motor must remain idle at
    // check()
    door.check();
    ASSERT_EQ(motor.direction(), MOTOR_IDLE);

    // "open" button pressed -> motor direction must be set to
    // "opening"
    do_open.set_state(PUSHBUTTON_PRESSED);
    door.check();
    ASSERT_EQ(motor.direction(), MOTOR_FORWARD);

    // "opened" position reached (light barrier's beam broken) ->
    // motor stopped
    opened_position.set_state(LIGHTBARRIER_BEAM_BROKEN);
    closed_position.set_state(LIGHTBARRIER_BEAM_SOLID);
    door.check();
    ASSERT_EQ(motor.direction(), MOTOR_IDLE);
}
