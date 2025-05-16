#include <gtest/gtest.h>
#include "door.h"

TEST(DoorTestSuite, straightforward_open)
{
    // Baue Tür und Komponenten
    Motor motor;  // Default ist MOTOR_IDLE
    PushButton doClose(PushButtonState::RELEASED);
    PushButton doOpen(PushButtonState::RELEASED);
    LightBarrier closedPosition(LightBarrierState::BEAM_BROKEN); // Tür ist "geschlossen"
    LightBarrier openedPosition(LightBarrierState::BEAM_SOLID);  // Tür ist nicht "geöffnet"

    Door door(&motor, &doClose, &doOpen, &closedPosition, &openedPosition);

    // Initialer Check: Lichtschranken deuten auf DOOR_CLOSED hin
    door.check();
    ASSERT_EQ(motor.getDirection(), MotorDirection::IDLE);
    
    // Wiederholter Check ohne Zustandsänderung
    door.check();
    ASSERT_EQ(motor.getDirection(), MotorDirection::IDLE);

    // Öffnungsanforderung: "open"-Button gedrückt
    doOpen.setState(PushButtonState::PRESSED);
    door.check();
    ASSERT_EQ(motor.getDirection(), MotorDirection::FORWARD);

    // Endposition erreicht (geöffnet), Motor sollte stoppen
    openedPosition.setState(LightBarrierState::BEAM_BROKEN);
    closedPosition.setState(LightBarrierState::BEAM_SOLID); // optional realitätsnaher Zustand

    door.check();
    ASSERT_EQ(motor.getDirection(), MotorDirection::IDLE);
}
