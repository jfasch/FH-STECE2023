#include <door.h>

#include <time.h>


int main()
{
    // --- build a door and its parts

    Motor Motor(MOTOR_IDLE);


    PushButton PushButton(PUSHBUTTON_RELEASED);


    PushButton PushButton(PUSHBUTTON_RELEASED);

    
    LightBarrier(LIGHTBARRIER_BEAM_BROKEN);  // <-- door in "closed" position

    LightBarrier opened_position;
    LightBarrier(LIGHTBARRIER_BEAM_SOLID);   // <-- door not in "opened" position

    
    Door Door(&motor, &do_close, &do_open, &closed_position, &opened_position);


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
