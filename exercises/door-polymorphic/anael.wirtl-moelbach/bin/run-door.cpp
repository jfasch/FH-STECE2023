#include "door.h"

#include "motor-mock.h"
#include "push-button-mock.h"
#include "light-barrier-mock.h"

#include <time.h>

int main()
{
    // --- build a door and its parts using mocks
    MotorMock motor(IMotor::Direction::IDLE);
    PushButtonMock do_close(IPushButton::State::RELEASED);
    PushButtonMock do_open(IPushButton::State::RELEASED);
    LightBarrierMock closed_position(ILightBarrier::State::BEAM_BROKEN);  // door is in "closed" position
    LightBarrierMock opened_position(ILightBarrier::State::BEAM_SOLID);   // door not in "opened" position

    Door door(&motor, &do_close, &do_open, &closed_position, &opened_position);

    // --- run main SPS loop
    struct timespec interval = {
        .tv_sec = 0,
        .tv_nsec = 1000 * 1000, // 1 millisecond
    };

    while (true) {
        door.check();
        nanosleep(&interval, nullptr);
    }

    return 0;
}
