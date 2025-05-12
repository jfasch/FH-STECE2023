#include <door.h>

#include <time.h>


int main()
{
    // --- build a door and its parts
    Motor motor;
    Motor_init(&motor, MOTOR_IDLE);

    PushButton do_close(PUSHBUTTON_RELEASED);
    PushButton do_open(PUSHBUTTON_RELEASED);

    LightBarrier closed_position;
    LightBarrier_init(&closed_position, LIGHTBARRIER_BEAM_BROKEN);  // <-- door in "closed" position

    LightBarrier opened_position;
    LightBarrier_init(&opened_position, LIGHTBARRIER_BEAM_SOLID);   // <-- door not in "opened" position

    Door door;
    Door_init(&door, &motor, &do_close, &do_open, &closed_position, &opened_position);


    // --- run main SPS loop
    struct timespec interval = {
        .tv_sec = 0,
        .tv_nsec = 1000*1000,      // <-- 1 millisecond
    };

    while (true) {
        Door_check(&door);
        nanosleep(&interval, nullptr);
    }

    return 0;
}
