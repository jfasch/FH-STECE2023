#include "door.h"
#include "motor.h"
#include "push-button.h"
#include "light-barrier.h"

#include <gtest/gtest.h>
//asdasd

TEST(door_suite, straightforward_open)
{
    // --- build a door and its parts
    Motor motor;  // default MOTOR_IDLE

    PushButton doClose(PushButton::PUSHBUTTON_PRESSED);
    PushButton doOpen(PushButton::PUSHBUTTON_RELEASED);

    LightBarrier closedPosition(LightBarrier::LIGHTBARRIER_BEAM_BROKEN);  // door in closed position
    LightBarrier openedPosition(LightBarrier::LIGHTBARRIER_BEAM_SOLID);   // not in open position

    Door door(&motor, &doClose, &doOpen, &closedPosition, &openedPosition);

    // Initial check - should detect door is CLOSED
    door.check();
    ASSERT_EQ(door.getState(), Door::State::CLOSED);

    // No buttons pressed -> motor remains idle
    door.check();
    ASSERT_EQ(motor.getDirection(), Motor::MOTOR_IDLE);
    //asda

    // Press "open" button -> door should start opening
    doOpen.PushButton_set_state(PushButton::PUSHBUTTON_PRESSED);
    door.check();
    ASSERT_EQ(motor.getDirection(), Motor::MOTOR_FORWARD);

    // Simulate that door has reached opened position
    openedPosition.setState(LightBarrier::LIGHTBARRIER_BEAM_BROKEN);
    closedPosition.setState(LightBarrier::LIGHTBARRIER_BEAM_SOLID);

    door.check();
    ASSERT_EQ(motor.getDirection(), Motor::MOTOR_IDLE);
}


