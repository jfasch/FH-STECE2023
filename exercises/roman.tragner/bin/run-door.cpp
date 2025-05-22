#include <door.h>

#include <time.h>


int main()
{
    // --- build a door and its parts
    Motor motor(IDLE);
    

    PushButton do_close(PUSHBUTTON_RELEASED);

    PushButton do_open(PUSHBUTTON_RELEASED);
 
    LightBarrier closed_position(BEAM_BROKEN);
   

    LightBarrier opened_position(BEAM_SOLID);
 

    Door door(&motor, &do_close, &do_open, &closed_position, &opened_position);
    


    // --- run main SPS loop
    struct timespec interval = {
        .tv_sec = 0,
        .tv_nsec = 1000*1000,      // <-- 1 millisecond
    };

    while (true) {
        door.check();
        nanosleep(&interval, nullptr);
    }

    return 0;
}
