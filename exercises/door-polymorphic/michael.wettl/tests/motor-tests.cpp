#include <motor-mock.h>

#include <gtest/gtest.h>


TEST(motor_suite, init)
{
    {
        Motor_Mock motor(Motor::Direction::IDLE);
        ASSERT_EQ(motor.get_direction(), Motor::Direction::IDLE);
    }
    {
        Motor_Mock motor(Motor::Direction::FORWARD);
        ASSERT_EQ(motor.get_direction(), Motor::Direction::FORWARD);
    }
    {
        Motor_Mock motor(Motor::Direction::BACKWARD);
        ASSERT_EQ(motor.get_direction(), Motor::Direction::BACKWARD);
    }
}
