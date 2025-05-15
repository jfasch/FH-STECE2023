#include <gtest/gtest.h>
#include "door.h"
#include "motor.h"
#include "push-button.h"
#include "light-barrier.h"

TEST(door_suite, straightforward_open)
{
    // build a door and its parts
    Motor motor(MotorDirection::IDLE);

    PushButton do_close(PushButtonState::RELEASED);
    PushButton do_open(PushButtonState::RELEASED);

    LightBarrier closed_position(LightBarrierState::BEAM_BROKEN);  // door closed
    LightBarrier opened_position(LightBarrierState::BEAM_SOLID);   // door not opened

    Door door(&motor, &do_close, &do_open, &closed_position, &opened_position);

    door.check();

    // Door state prüfen → wir brauchen einen Getter für _state in Door
    ASSERT_EQ(door.get_state(), DoorState::CLOSED);

    // all idle: no button pressed -> motor must remain idle at check()
    door.check();
    ASSERT_EQ(motor.get_direction(), MotorDirection::IDLE);

    // "open" button pressed -> motor direction must be forward/opening
    do_open.set_state(PushButtonState::PRESSED);
    door.check();
    ASSERT_EQ(motor.get_direction(), MotorDirection::FORWARD);

    // "opened" position reached (light barrier beam broken) -> motor stopped
    opened_position.set_state(LightBarrierState::BEAM_BROKEN);
    closed_position.set_state(LightBarrierState::BEAM_SOLID);
    door.check();
    ASSERT_EQ(motor.get_direction(), MotorDirection::IDLE);
}


/*
#include <gtest/gtest.h>

#include <door.h>


TEST(door_suite, straightforward_open)
{
    // build a door and its parts
    Motor motor;
    Motor_init(&motor, MOTOR_IDLE);

    PushButton do_close;
    PushButton_init(&do_close, PUSHBUTTON_RELEASED);

    PushButton do_open;
    PushButton_init(&do_open, PUSHBUTTON_RELEASED);

    LightBarrier closed_position;
    LightBarrier_init(&closed_position, LIGHTBARRIER_BEAM_BROKEN);  // <-- door in "closed" position

    LightBarrier opened_position;
    LightBarrier_init(&opened_position, LIGHTBARRIER_BEAM_SOLID);   // <-- door not in "opened" position

    Door door;
    Door_init(&door, &motor, &do_close, &do_open, &closed_position, &opened_position);

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
*/