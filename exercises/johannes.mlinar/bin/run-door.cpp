#include <door.h>

#include <time.h>


int main()
{
    // --- build a door and its parts
    Motor motor = Motor(Motor::BACKWARD);
    PushButton do_close = PushButton(PushButton::PUSHBUTTON_RELEASED);
    PushButton do_open = PushButton(PushButton::PUSHBUTTON_RELEASED);
    LightBarrier closed_position = LightBarrier(LightBarrier::LIGHTBARRIER_BEAM_BROKEN);
    LightBarrier opened_position= LightBarrier(LightBarrier::LIGHTBARRIER_BEAM_SOLID);
    Door door = Door(&motor, &do_close, &do_open, &closed_position, &opened_position);


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
