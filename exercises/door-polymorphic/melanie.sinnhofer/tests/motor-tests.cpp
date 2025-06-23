#include <motor.h>

#include <gtest/gtest.h>
#include <motor-mock.h>

TEST(motor_suite, init)
{
    {
        MotorMock motor(MotorMock::Direction::IDLE);
        ASSERT_EQ(motor.get_direction(), Motor::Direction::IDLE);
    }
    {
        MotorMock motor(MotorMock::Direction::FORWARD);
        ASSERT_EQ(motor.get_direction(), Motor::Direction::FORWARD);
    }
    {
        MotorMock motor(MotorMock::Direction::BACKWARD);
        ASSERT_EQ(motor.get_direction(), Motor::Direction::BACKWARD);
    }
}
