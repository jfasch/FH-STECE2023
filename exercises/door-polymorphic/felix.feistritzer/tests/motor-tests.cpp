#include <motor.h>
#include "motor-mock.h"

#include <gtest/gtest.h>


TEST(motor_suite, init)
{
    {
        MockMotor motor(Motor::Direction::IDLE);
        ASSERT_EQ(motor.get_direction(), Motor::Direction::IDLE);
    }
    {
        MockMotor motor(Motor::Direction::FORWARD);
        ASSERT_EQ(motor.get_direction(), Motor::Direction::FORWARD);
    }
    {
        MockMotor motor(Motor::Direction::BACKWARD);
        ASSERT_EQ(motor.get_direction(), Motor::Direction::BACKWARD);
    }
}
