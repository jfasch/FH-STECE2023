#include <door.h>

#include <time.h>

int main()
{
    // --- build a door and its parts
    Motor motor(Motor::Direction::IDLE);

    PushButton do_close(PushButton::State::PUSHBUTTON_RELEASED);

    PushButton do_open(PushButton::State::PUSHBUTTON_RELEASED);
    
    LightBarrier closed_position(LightBarrier::State::BeamBroken);  // <-- door in "closed" position
    
    LightBarrier opened_position(LightBarrier::State::BeamSolid);   // <-- door not in "opened" position
    
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
