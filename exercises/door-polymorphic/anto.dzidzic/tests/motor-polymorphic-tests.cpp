#include <motor-mock.h>

#include <gtest/gtest.h>


TEST(motor_polymorphic_suite, base_conversion)
{
    MotorMock motor(IMotor::Direction::IDLE);
    [[maybe_unused]] IMotor* base = &motor;             // <-- derived converted to base
}

TEST(motor_polymorphic_suite, access_through_base)
{
    MotorMock motor(IMotor::Direction::IDLE);
    IMotor* base = &motor;
    ASSERT_EQ(base->get_direction(), IMotor::Direction::IDLE);

    base->forward();                                   // <-- through base, derived's forward is called
    ASSERT_EQ(motor.get_direction(), IMotor::Direction::FORWARD);
}
