#include <gtest/gtest.h>

#include <door.h>


TEST(door_suite, straightforward_open)
{
    // build a door and its parts
    Motor motor(MotorDirection::MOTOR_IDLE);

    PushButton do_close(PushButtonState::PUSHBUTTON_RELEASED);

    PushButton do_open(PushButtonState::PUSHBUTTON_PRESSED);

    LightBarrier closed_position(LightBarrierState::LIGHTBARRIER_BEAM_BROKEN);  // <-- door in "closed" position

    LightBarrier opened_position(LightBarrierState::LIGHTBARRIER_BEAM_SOLID);   // <-- door not in "opened" position

    Door door(&motor, &do_close, &do_open, &closed_position, &opened_position);

    door.Door_check();
    ASSERT_EQ(door.get_state(), DoorState::DOOR_CLOSED);         // <-- inferred from the light barrier situation

    // all idle: no button pressed -> motor must remain idle at
    // check()
    door.Door_check();
    ASSERT_EQ(motor.get_direction(), MotorDirection::MOTOR_IDLE);

    // "open" button pressed -> motor direction must be set to
    // "opening"
    do_open.set_state(PushButtonState::PUSHBUTTON_PRESSED);
    door.Door_check();    
    ASSERT_EQ(motor.get_direction(), MotorDirection::MOTOR_FORWARD);

    // "opened" position reached (light barrier's beam broken) ->
    // motor stopped
    opened_position.set_state(LightBarrierState::LIGHTBARRIER_BEAM_BROKEN);
    closed_position.set_state(LightBarrierState::LIGHTBARRIER_BEAM_SOLID);    // <-- should probably be verified by door logic: 
                                                                          //     if one beam is broken, the other must be solid, 
                                                                          //     and vice versa
    door.Door_check();
    ASSERT_EQ(motor.get_direction(), MotorDirection::MOTOR_IDLE);
}
