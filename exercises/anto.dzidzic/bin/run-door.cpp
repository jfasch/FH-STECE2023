#include "door.h"
#include "motor.h"
#include "push-button.h"
#include "light-barrier.h"
#include <iostream>
#include <chrono>
#include <thread>

int main()
{
    // Create components
    Motor motor;
    PushButton buttonClose;
    PushButton buttonOpen;
    //LightBarrier closedPosition;
    //LightBarrier openedPosition;

    // Set initial states
    buttonClose.PushButton_set_state(PushButton::PUSHBUTTON_RELEASED);
    buttonOpen.PushButton_set_state(PushButton::PUSHBUTTON_RELEASED);
    LightBarrier closedPosition(LightBarrier::LIGHTBARRIER_BEAM_BROKEN); // e.g. door is closed
    LightBarrier openedPosition(LightBarrier::LIGHTBARRIER_BEAM_SOLID);  // e.g. door is not fully open

    // Create Door
    Door door(&motor, &buttonClose, &buttonOpen, &closedPosition, &openedPosition);

    // Loop
    using namespace std::chrono_literals;
    while (true) {
        door.check();
        std::this_thread::sleep_for(1ms);
    }

    return 0;
}


//int main()
//{
//    // --- build a door and its parts
//    Motor motor;
//    Motor_init(&motor, MOTOR_IDLE);
//
//    PushButton do_close;
//    PushButton_init(&do_close, PUSHBUTTON_RELEASED);
//
//    PushButton do_open;
//    PushButton_init(&do_open, PUSHBUTTON_RELEASED);
//
//    LightBarrier closed_position;
//    LightBarrier_init(&closed_position, LIGHTBARRIER_BEAM_BROKEN);  // <-- door in "closed" position
//
//    LightBarrier opened_position;
//    LightBarrier_init(&opened_position, LIGHTBARRIER_BEAM_SOLID);   // <-- door not in "opened" position
//
//    Door door;
//    Door_init(&door, &motor, &do_close, &do_open, &closed_position, &opened_position);
//
//
//    // --- run main SPS loop
//    struct timespec interval = {
//        .tv_sec = 0,
//        .tv_nsec = 1000*1000,      // <-- 1 millisecond
//    };
//
//    while (true) {
//        Door_check(&door);
//        nanosleep(&interval, nullptr);
//    }
//
//    return 0;
//}
