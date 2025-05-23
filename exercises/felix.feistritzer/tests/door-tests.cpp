#include <gtest/gtest.h>

#include <door.h>


TEST(door_suite, straightforward_open)
{
    // build a door and its parts
    Motor motor(MotorDirection::IDLE);

    PushButton do_close(PushButtonState::RELEASED);

    PushButton do_open(PushButtonState::RELEASED);

    LightBarrier closed_position(LightBarrierState::BEAM_BROKEN);  // <-- door in "closed" position

    LightBarrier opened_position(LightBarrierState::BEAM_SOLID);   // <-- door not in "opened" position

    Door door(&motor, &do_close, &do_open, &closed_position, &opened_position);

    door.check();
    ASSERT_EQ(door.get_state(), DoorState::CLOSED);                // <-- inferred from the light barrier situation

    // all idle: no button pressed -> motor must remain idle at
    // check()
    door.check();
    ASSERT_EQ(motor.get_direction(), MotorDirection::IDLE);

    // "open" button pressed -> motor direction must be set to
    // "opening"
    do_open.set_state(PushButtonState::PRESSED);
    door.check();    
    ASSERT_EQ(motor.get_direction(), MotorDirection::FORWARD);

    // "opened" position reached (light barrier's beam broken) ->
    // motor stopped
    opened_position.set_state(LightBarrierState::BEAM_BROKEN);
    closed_position.set_state(LightBarrierState::BEAM_SOLID);    // <-- should probably be verified by door logic: 
                                                                          //     if one beam is broken, the other must be solid, 
                                                                          //     and vice versa
    door.check();
    ASSERT_EQ(motor.get_direction(), MotorDirection::IDLE);
}
