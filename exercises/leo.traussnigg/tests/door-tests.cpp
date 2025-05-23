#include <gtest/gtest.h>

#include <door.h>


TEST(door_suite, straightforward_open)
{
    // build a door and its parts
    Motor motor(Motor::Direction::IDLE);

    PushButton do_close(PushButton::State::PUSHBUTTON_RELEASED);

    PushButton do_open(PushButton::State::PUSHBUTTON_RELEASED);

    LightBarrier closed_position(LightBarrier::State::BeamBroken);  // <-- door in "closed" position

    LightBarrier opened_position(LightBarrier::State::BeamSolid);   // <-- door not in "opened" position

    Door door(&motor, &do_close, &do_open, &closed_position, &opened_position);

    door.check();
    ASSERT_EQ(door.getState(), Door::State::CLOSED);                // <-- inferred from the light barrier situation

    // all idle: no button pressed -> motor must remain idle at
    // check()
    door.check();
    ASSERT_EQ(motor.getDirection(), Motor::Direction::IDLE);

    // "open" button pressed -> motor direction must be set to
    // "opening"
    do_open.setState(PushButton::State::PUSHBUTTON_PRESSED);
    
    door.check();    
    ASSERT_EQ(motor.getDirection(), Motor::Direction::FORWARD);

    // "opened" position reached (light barrier's beam broken) ->
    // motor stopped
    opened_position.setState(LightBarrier::State::BeamBroken);
    closed_position.setState(LightBarrier::State::BeamSolid);    // <-- should probably be verified by door logic: 
                                                                          //     if one beam is broken, the other must be solid, 
                                                                          //     and vice versa
    door.check();
    ASSERT_EQ(motor.getDirection(), Motor::Direction::IDLE);
}
