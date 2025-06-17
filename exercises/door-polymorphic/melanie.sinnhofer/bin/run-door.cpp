#include <door.h>
#include <time.h>

#include <motor-mock.h>
#include <light-barrier-mock.h>
#include <push-button-mock.h>

int main()
{
    // --- build a door and its parts
    MotorMock motor(MotorMock::Direction::IDLE);
    PushButtonMock do_close(PushButtonMock::State::RELEASED);
    PushButtonMock do_open(PushButtonMock::State::RELEASED);
    LightBarrierMock closed_position(LightBarrierMock::State::BEAM_BROKEN);  // <-- door in "closed" position
    LightBarrierMock opened_position(LightBarrierMock::State::BEAM_SOLID);   // <-- door not in "opened" position

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


//test