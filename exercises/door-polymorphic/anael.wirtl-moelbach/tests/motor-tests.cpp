#include "motor-mock.h"
#include <gtest/gtest.h>

TEST(motor_suite, init)
{
    {
        MotorMock motor(IMotor::Direction::IDLE);
        ASSERT_EQ(motor.get_direction(), IMotor::Direction::IDLE);
    }
    {
        MotorMock motor(IMotor::Direction::FORWARD);
        ASSERT_EQ(motor.get_direction(), IMotor::Direction::FORWARD);
    }
    {
        MotorMock motor(IMotor::Direction::BACKWARD);
        ASSERT_EQ(motor.get_direction(), IMotor::Direction::BACKWARD);
    }
}
