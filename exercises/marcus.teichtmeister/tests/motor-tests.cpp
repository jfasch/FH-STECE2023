#include <motor.h>

#include <gtest/gtest.h>


TEST(motor_suite, init)
{
    {
        Motor motor;
        Motor_init(&motor, MOTOR_IDLE);
        ASSERT_EQ(Motor_get_direction(&motor), MOTOR_IDLE);
    }
    {
        Motor motor;
        Motor_init(&motor, MOTOR_FORWARD);
        ASSERT_EQ(Motor_get_direction(&motor), MOTOR_FORWARD);
    }
    {
        Motor motor;
        Motor_init(&motor, MOTOR_BACKWARD);
        ASSERT_EQ(Motor_get_direction(&motor), MOTOR_BACKWARD);
    }
}