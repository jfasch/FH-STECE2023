#include <motor.h>

#include <gtest/gtest.h>


TEST(motor_suite, init)
{
    {
        Motor motor;
        motor.init(Motor::MotorDirection::MOTOR_IDLE);
        ASSERT_EQ(motor.get_direction(), Motor::MotorDirection::MOTOR_IDLE);
    }
    {
        Motor motor;
        motor.init(Motor::MotorDirection::MOTOR_FORWARD);
        ASSERT_EQ(motor.get_direction(), Motor::MotorDirection::MOTOR_FORWARD);
    }
    {
  Motor motor;
        motor.init(Motor::MotorDirection::MOTOR_BACKWARD);
        ASSERT_EQ(motor.get_direction(), Motor::MotorDirection::MOTOR_BACKWARD);
    }
}
