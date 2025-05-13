#include "../lib/door.h"

#include <time.h>


int main()
{

    Motor motor(MOTOR_IDLE);
    PushButton do_close(PUSHBUTTON_RELEASED);
    PushButton do_open(PUSHBUTTON_RELEASED);
    LightBarrier closed_position(LIGHTBARRIER_BEAM_BROKEN);
    LightBarrier opened_position(LIGHTBARRIER_BEAM_SOLID);

    //Door door;
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
