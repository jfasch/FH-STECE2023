#include <gtest/gtest.h>
#include <door.h>
#include <motor.h>
#include <push-button.h>
#include <light-barrier.h>

TEST(door_suite, straightforward_open)
{
  
    Motor motor;
    PushButton do_close(PushButton::State::RELEASED);
    PushButton do_open(PushButton::State::RELEASED);
    LightBarrier closed_position(LightBarrier::State::BEAM_BROKEN);  
    LightBarrier opened_position(LightBarrier::State::BEAM_SOLID);   

    Door door(&motor, &do_close, &do_open, &closed_position, &opened_position);

    
    door.check();
    ASSERT_EQ(door.getState(), Door::State::CLOSED);

  
    door.check();
    ASSERT_EQ(motor.getDirection(), Motor::Direction::IDLE);

    
    do_open.setState(PushButton::State::PRESSED);
    door.check();
    ASSERT_EQ(motor.getDirection(), Motor::Direction::FORWARD);

    
    opened_position.setState(LightBarrier::State::BEAM_BROKEN);
    closed_position.setState(LightBarrier::State::BEAM_SOLID);  
    door.check();
    ASSERT_EQ(motor.getDirection(), Motor::Direction::IDLE);
}