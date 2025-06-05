#include <gtest/gtest.h>
#include <door.h>
#include "motor-mock.h"        
#include "push-button-mock.h"  
#include "light-barrier-mock.h"

TEST(door_suite, straightforward_open)
{
    // Mock-Objekte mit Startzustand erzeugen
    MotorMock motor(MotorMock::Direction::IDLE);
    PushButtonMock do_close(PushButtonMock::State::RELEASED);
    PushButtonMock do_open(PushButtonMock::State::RELEASED);
    LightBarrierMock closed_position(LightBarrierMock::State::BEAM_BROKEN);  // Tür ist geschlossen
    LightBarrierMock opened_position(LightBarrierMock::State::BEAM_SOLID);   // Tür ist nicht offen

    Door door(&motor, &do_close, &do_open, &closed_position, &opened_position);

    door.check();
    ASSERT_EQ(door.get_state(), Door::State::CLOSED);

    door.check();
    ASSERT_EQ(motor.get_direction(), MotorMock::Direction::IDLE);

    do_open.set_state(PushButtonMock::State::PRESSED);
    door.check();
    ASSERT_EQ(motor.get_direction(), MotorMock::Direction::FORWARD);

    opened_position.set_state(LightBarrierMock::State::BEAM_BROKEN);
    closed_position.set_state(LightBarrierMock::State::BEAM_SOLID);
    door.check();
    ASSERT_EQ(motor.get_direction(), MotorMock::Direction::IDLE);
}
