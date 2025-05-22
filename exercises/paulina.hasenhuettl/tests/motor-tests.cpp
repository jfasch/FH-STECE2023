#include <motor.h>  
#include <gtest/gtest.h>

TEST(motor_suite, init)
{
    {
        Motor motor;  
        ASSERT_EQ(motor.get_direction(), MotorDirection::IDLE);
    }
    {
        Motor motor(MotorDirection::FORWARD);
        ASSERT_EQ(motor.get_direction(), MotorDirection::FORWARD);
    }
    {
        Motor motor(MotorDirection::BACKWARD);
        ASSERT_EQ(motor.get_direction(), MotorDirection::BACKWARD);
    }
}


/*
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
*/