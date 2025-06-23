#include <motor-mock.h>

#include <gtest/gtest.h>


TEST(motor_suite, init)
{
        MotorMock motor(Motor::Direction::IDLE);
        ASSERT_EQ(motor.get_direction(), Motor::Direction::IDLE);

        motor.forward();
        ASSERT_EQ(motor.get_direction(), Motor::Direction::FORWARD);

        motor.backward();
        ASSERT_EQ(motor.get_direction(), Motor::Direction::BACKWARD);

        motor.stop();
        ASSERT_EQ(motor.get_direction(), Motor::Direction::IDLE);
}
