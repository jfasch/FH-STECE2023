#include <motor.h>

#include <gtest/gtest.h>


TEST(motor_suite, init)
{
    {
        Motor motor(MotorDirection::MOTOR_IDLE);
        ASSERT_EQ(motor.get_direction(), MotorDirection::MOTOR_IDLE);
    }
    {
        Motor motor(MotorDirection::MOTOR_FORWARD);
        ASSERT_EQ(motor.get_direction(), MotorDirection::MOTOR_FORWARD);
    }
    {
        Motor motor(MotorDirection::MOTOR_BACKWARD);
        ASSERT_EQ(motor.get_direction(), MotorDirection::MOTOR_BACKWARD);
    }
}
