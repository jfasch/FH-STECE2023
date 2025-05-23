#include <gtest/gtest.h>

#include <door.h>

#include "motor-mock.h"
#include "light-barrier-mock.h"
#include "push-button-mock.h"

TEST(door_suite, straightforward_open)
{
    // build a door and its parts
    MotorMock motor(Motor::Direction::IDLE);
    PushButtonMock do_close(PushButton::State::RELEASED);
    PushButtonMock do_open(PushButton::State::RELEASED);
    LightBarrierMock closed_position(LightBarrier::State::BEAM_BROKEN);  // <-- door in "closed" position
    LightBarrierMock opened_position(LightBarrier::State::BEAM_SOLID);   // <-- door not in "opened" position

    Door door(&motor, &do_close, &do_open, &closed_position, &opened_position);

    door.check();
    ASSERT_EQ(door.get_state(), Door::State::CLOSED);                // <-- inferred from the light barrier situation

    // all idle: no button pressed -> motor must remain idle at
    // check()
    door.check();
    ASSERT_EQ(motor.get_direction(), Motor::Direction::IDLE);

    // "open" button pressed -> motor direction must be set to
    // "opening"
    do_open.set_state(PushButton::State::PRESSED);
    door.check();    
    ASSERT_EQ(motor.get_direction(), Motor::Direction::FORWARD);

    // "opened" position reached (light barrier's beam broken) ->
    // motor stopped
    opened_position.set_state(LightBarrier::State::BEAM_BROKEN);
    closed_position.set_state(LightBarrier::State::BEAM_SOLID);    // <-- should probably be verified by door logic: 
                                                                   //     if one beam is broken, the other must be solid, 
                                                                   //     and vice versa
    door.check();
    ASSERT_EQ(motor.get_direction(), Motor::Direction::IDLE);
}
