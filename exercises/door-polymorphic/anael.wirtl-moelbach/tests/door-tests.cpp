#include <gtest/gtest.h>

#include <door.h>                     // verwendet nur Interfaces
#include <motor-mock.h>              // enthält MotorMock
#include <push-button-mock.h>        // enthält PushButtonMock
#include <light-barrier-mock.h>      // enthält LightBarrierMock

TEST(door_suite, straightforward_open)
{
    // --- Komponenten bauen ---
    MotorMock motor(IMotor::Direction::IDLE);
    PushButtonMock do_close(IPushButton::State::RELEASED);
    PushButtonMock do_open(IPushButton::State::RELEASED);
    LightBarrierMock closed_position(ILightBarrier::State::BEAM_BROKEN);   // Tür geschlossen
    LightBarrierMock opened_position(ILightBarrier::State::BEAM_SOLID);    // Tür nicht geöffnet

    Door door(&motor, &do_close, &do_open, &closed_position, &opened_position);

    // --- Startstatus prüfen ---
    door.check();
    ASSERT_EQ(door.get_state(), Door::State::CLOSED);

    // --- Alles idle ---
    door.check();
    ASSERT_EQ(motor.get_direction(), IMotor::Direction::IDLE);

    // --- Öffnen ---
    do_open.set_state(IPushButton::State::PRESSED);
    door.check();
    ASSERT_EQ(motor.get_direction(), IMotor::Direction::FORWARD);

    // --- Tür vollständig geöffnet ---
    opened_position.set_state(ILightBarrier::State::BEAM_BROKEN);
    closed_position.set_state(ILightBarrier::State::BEAM_SOLID);
    door.check();
    ASSERT_EQ(motor.get_direction(), IMotor::Direction::IDLE);
}
