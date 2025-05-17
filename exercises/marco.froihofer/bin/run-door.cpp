#include "door.h"
#include "motor.h"
#include "push-button.h"
#include "light-barrier.h"

#include <time.h>

int main()
{
    // --- build a door and its parts
    Motor motor;
    motor.init(MotorDirection::IDLE);

    PushButton do_close(PushButtonState::PUSHBUTTON_RELEASED);
    PushButton do_open(PushButtonState::PUSHBUTTON_RELEASED);

    LightBarrier closed_position(LightBarrierState::BEAM_BROKEN);   // Tür geschlossen
    LightBarrier opened_position(LightBarrierState::BEAM_SOLID);    // Tür nicht geöffnet

    Door door(&motor, &do_close, &do_open, &closed_position, &opened_position);

    // --- run main SPS loop
    struct timespec interval = {
        .tv_sec = 0,
        .tv_nsec = 1000 * 1000,   // 1 Millisekunde
    };

    while (true) {
        door.check();
        nanosleep(&interval, nullptr);
    }

    return 0;
}
