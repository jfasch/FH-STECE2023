#include <door.h>

#include <time.h>


int main()
{
    Motor motor;

    // Lösung 2: mit Initialzustand
    PushButton do_close(PushButton::PushButtonState::PUSHBUTTON_RELEASED);
    PushButton do_open(PushButton::PushButtonState::PUSHBUTTON_RELEASED);

    LightBarrier closed_position(LightBarrier::LightBarrierState::LIGHTBARRIER_BEAM_BROKEN);
    LightBarrier opened_position(LightBarrier::LightBarrierState::LIGHTBARRIER_BEAM_SOLID);

    Door door(&motor, &do_close, &do_open, &closed_position, &opened_position);

    struct timespec interval = {
        .tv_sec = 0,
        .tv_nsec = 1000*1000,
    };

    while (true) {
        door.check();
        nanosleep(&interval, nullptr);
    }

    return 0;
}
