#include <gtest/gtest.h>

#include <door.h>

TEST(door_suite, straightforward_open)
{

Motor motor;
motor.init(Motor::MotorDirection::MOTOR_IDLE);

    PushButton do_close(PushButton::PushButtonState::PUSHBUTTON_RELEASED);
    PushButton do_open(PushButton::PushButtonState::PUSHBUTTON_RELEASED);

    LightBarrier closed_position(LightBarrier::LightBarrierState::LIGHTBARRIER_BEAM_BROKEN);  // Tür ist geschlossen
    LightBarrier opened_position(LightBarrier::LightBarrierState::LIGHTBARRIER_BEAM_SOLID);   // Tür ist nicht geöffnet

    Door door(&motor, &do_close, &do_open, &closed_position, &opened_position);

    door.check();
    ASSERT_EQ(door.get_state(), Door::DoorState::DOOR_CLOSED);


    ASSERT_EQ(motor.get_direction(), Motor::MotorDirection::MOTOR_IDLE);


    do_open.set_state(PushButton::PushButtonState::PUSHBUTTON_PRESSED);
    door.check();
    ASSERT_EQ(motor.get_direction(), Motor::MotorDirection::MOTOR_FORWARD);


    opened_position.set_state(LightBarrier::LightBarrierState::LIGHTBARRIER_BEAM_BROKEN);
    closed_position.set_state(LightBarrier::LightBarrierState::LIGHTBARRIER_BEAM_SOLID);
    door.check();
    ASSERT_EQ(motor.get_direction(), Motor::MotorDirection::MOTOR_IDLE);
}
