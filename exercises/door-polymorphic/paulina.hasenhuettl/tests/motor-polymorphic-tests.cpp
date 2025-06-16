#include "motor-mock.h"
#include <gtest/gtest.h>

TEST(motor_polymorphic_suite, base_conversion)
{
    MotorMock motor(Motor::Direction::IDLE);
    [[maybe_unused]] Motor* base = &motor; // Ableitung zu abstrakter Basisklasse
}

TEST(motor_polymorphic_suite, access_through_base)
{
    MotorMock motor(Motor::Direction::IDLE);
    Motor* base = &motor;

    ASSERT_EQ(base->get_direction(), Motor::Direction::IDLE);

    base->forward();
    ASSERT_EQ(motor.get_direction(), Motor::Direction::FORWARD);
}
