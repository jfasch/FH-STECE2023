#include <door.h>

#include <time.h>


int main()
{
    // --- build a door and its parts
    Motor motor(MotorDirection::MOTOR_IDLE);

    PushButton do_close(PushButtonState::PUSHBUTTON_PRESSED);

    PushButton do_open(PushButtonState::PUSHBUTTON_RELEASED);

    LightBarrier closed_position(LightBarrierState::LIGHTBARRIER_BEAM_BROKEN);

    LightBarrier opened_position(LightBarrierState::LIGHTBARRIER_BEAM_SOLID);

    Door door(&motor, &do_close, &do_open, &closed_position, &opened_position);

    // --- run main SPS loop
    struct timespec interval = {
        .tv_sec = 0,
        .tv_nsec = 1000*1000,      // <-- 1 millisecond
    };

    while (true) {
        door.Door_check();
        nanosleep(&interval, nullptr);
    }

    return 0;
}
