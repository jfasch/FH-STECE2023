#include <motor.h>

#include <gtest/gtest.h>


TEST(motor_suite, init)
{
    {
        Motor motor(MotorDirection::IDLE);
        ASSERT_EQ(motor.getDirection(), MotorDirection::IDLE);
    }
    {
        Motor motor;
        ASSERT_EQ(motor.getDirection(), MotorDirection::FORWARD);
    }
    {
        Motor motor;
        ASSERT_EQ(motor.getDirection(), MotorDirection::BACKWARD);
    }
}
