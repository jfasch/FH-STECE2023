#include <door.h>

#include <time.h>


int main()
{
    // --- build a door and its parts
    Motor motor(MOTOR_IDLE);
    //Motor_init(&motor, MOTOR_IDLE);

    PushButton do_close(PUSHBUTTON_RELEASED);
    //do_close->PushButton;

    PushButton do_open(PUSHBUTTON_RELEASED);
    //do_open.PushButton(do_open, PUSHBUTTON_RELEASED);

    LightBarrier closed_position(LIGHTBARRIER_BEAM_BROKEN);
    //LightBarrier_init(&closed_position, LIGHTBARRIER_BEAM_BROKEN);  // <-- door in "closed" position

    LightBarrier opened_position(LIGHTBARRIER_BEAM_SOLID);
    //LightBarrier_init(&opened_position, LIGHTBARRIER_BEAM_SOLID);   // <-- door not in "opened" position

    Door door(&motor, &do_close, &do_open, &closed_position, &opened_position);
    //Door_init(&door, &motor, &do_close, &do_open, &closed_position, &opened_position);


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
