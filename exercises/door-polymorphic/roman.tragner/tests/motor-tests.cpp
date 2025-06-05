#include <motor-mock.h>

#include <gtest/gtest.h>


TEST(motor_suite, init)
{
    {
        MotorMock motor(Motor::Direction::IDLE);
        ASSERT_EQ(motor.get_direction(), Motor::Direction::IDLE);
    }
    {
        MotorMock motor(Motor::Direction::FORWARD);
        ASSERT_EQ(motor.get_direction(), Motor::Direction::FORWARD);
    }
    {
        MotorMock motor(Motor::Direction::BACKWARD);
        ASSERT_EQ(motor.get_direction(), Motor::Direction::BACKWARD);
    }
}