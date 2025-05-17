#include <gtest/gtest.h>
#include <door.h>

TEST(door_suite, straightforward_open)
{
    // --- Setup: door and its components
    Motor motor(MotorDirection::IDLE);
    PushButton do_close(PUSHBUTTON_RELEASED);
    PushButton do_open(PUSHBUTTON_RELEASED);

    LightBarrier closed_position(LightBarrierState::BEAM_BROKEN);  // Tür ist geschlossen
    LightBarrier opened_position(LightBarrierState::BEAM_SOLID);   // Tür ist nicht offen

    Door door(&motor, &do_close, &do_open, &closed_position, &opened_position);

    // --- Initial check: Tür muss als geschlossen erkannt werden
    door.check();
    ASSERT_EQ(door.getState(), DoorState::CLOSED);

    // --- Keine Taste gedrückt: Motor muss idle bleiben
    door.check();
    ASSERT_EQ(motor.getDirection(), MotorDirection::IDLE);

    // --- "open" gedrückt: Motor muss vorwärts laufen
    do_open.set_state(PUSHBUTTON_PRESSED);
    door.check();
    ASSERT_EQ(motor.getDirection(), MotorDirection::FORWARD);

    // --- Tür öffnet sich vollständig: Motor muss stoppen
    opened_position.set_state(LightBarrierState::BEAM_BROKEN);
    closed_position.set_state(LightBarrierState::BEAM_SOLID);
    door.check();
    ASSERT_EQ(motor.getDirection(), MotorDirection::IDLE);
}
