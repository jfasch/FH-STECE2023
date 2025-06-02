#include <gtest/gtest.h>

#include <door.h>

#include "motor-mock.h"
#include "push-button-mock.h"
#include "light-barrier-mock.h"

TEST(door_suite, straightforward_open)
{
    // build a door and its parts
    MotorMock motor(Motor::Direction::IDLE);
    PushButtonMock do_close(PushButton::State::RELEASED);
    PushButtonMock do_open(PushButton::State::RELEASED);
    LightBarrierMock closed_position(LightBarrier::State::BEAM_BROKEN);  
    LightBarrierMock opened_position(LightBarrier::State::BEAM_SOLID);   

    Door door(&motor, &do_close, &do_open, &closed_position, &opened_position);

    door.check();
    ASSERT_EQ(door.get_state(), Door::State::CLOSED);                

 

    door.check();
    ASSERT_EQ(motor.get_direction(), Motor::Direction::IDLE);


    do_open.set_state(PushButton::State::PRESSED);
    door.check();    
    ASSERT_EQ(motor.get_direction(), Motor::Direction::FORWARD);

  

    opened_position.set_state(LightBarrier::State::BEAM_BROKEN);
    closed_position.set_state(LightBarrier::State::BEAM_SOLID);    

    door.check();
    ASSERT_EQ(motor.get_direction(), Motor::Direction::IDLE);
}