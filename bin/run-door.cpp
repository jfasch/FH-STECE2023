#include <door/door.h>
#include <door/motor-mock.h>
#include <door/push-button-mock.h>
#include <door/light-barrier-mock.h>
#include <door/timespec.h>

#include <iostream>


int main()
{
    // --- build a door and its parts
    MotorMock motor(Motor::Direction::IDLE);
    PushButtonMock do_close(PushButton::State::RELEASED);
    PushButtonMock do_open(PushButton::State::RELEASED);
    LightBarrierMock closed_position(LightBarrier::State::BEAM_BROKEN);  // <-- door in "closed" position
    LightBarrierMock opened_position(LightBarrier::State::BEAM_SOLID);   // <-- door not in "opened" position

    Door door(&motor, &do_close, &do_open, &closed_position, &opened_position);


    // --- run main SPS loop
    auto interval = TimeSpec::from_milliseconds(1);

    while (true) {
        // call door logic, and complain about cycle-time violation
        auto before = TimeSpec::now_monotonic();
        door.check();
        auto after = TimeSpec::now_monotonic();

        auto spent = after - before;
        if (spent > interval)
            std::cerr << "WARNING: door logic exceeds interval" << std::endl;

        // suspend for the rest of the interval
        auto suspend = interval - spent;
        nanosleep(&suspend, nullptr);
    }

    return 0;
}
