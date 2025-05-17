#include <motor.h>

#include <gtest/gtest.h>


TEST(motor_suite, init)
{
    {
        Motor motor(MOTOR_IDLE);
        ASSERT_EQ(motor.direction(), MOTOR_IDLE);
    }

    {
        Motor motor(MOTOR_FORWARD);
        ASSERT_EQ(motor.direction(), MOTOR_FORWARD);
    }

    {
        Motor motor(MOTOR_BACKWARD);
        ASSERT_EQ(motor.direction(), MOTOR_BACKWARD);
    }
}
