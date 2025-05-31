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

#include <motor.h>
#include <gtest/gtest.h>

TEST(motor_suite, init)
{
    {
        // Initialize motor with IDLE direction
        Motor motor(Motor::Direction::IDLE);
        ASSERT_EQ(motor.getDirection(), Motor::Direction::IDLE);
    }
    {
        // Initialize motor with FORWARD direction
        Motor motor(Motor::Direction::FORWARD);
        ASSERT_EQ(motor.getDirection(), Motor::Direction::FORWARD);
    }
    {
        // Initialize motor with BACKWARD direction
        Motor motor(Motor::Direction::BACKWARD);
        ASSERT_EQ(motor.getDirection(), Motor::Direction::BACKWARD);
    }
}