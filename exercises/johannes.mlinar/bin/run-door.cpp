

#include "door.h"
#include <thread>
#include <chrono>

int main() {
    Motor motor(MotorDirection::BACKWARD);
    PushButton doClose(PushButtonState::RELEASED);
    PushButton doOpen(PushButtonState::RELEASED);
    LightBarrier closed(LightBarrierState::BEAM_BROKEN);
    LightBarrier opened(LightBarrierState::BEAM_SOLID);

    Door door(&motor, &doClose, &doOpen, &closed, &opened);

    while (true) {
        door.check();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    return 0;
}
