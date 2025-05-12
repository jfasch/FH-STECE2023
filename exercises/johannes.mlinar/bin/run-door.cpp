#include <door.h>

#include <time.h>


/*************  ✨ Windsurf Command ⭐  *************/
/**
 * @brief The main function of the SPS door example.
 *
 * It builds an SPS door object and its parts and then runs the main loop.
 * The main loop calls Door_check() every millisecond.
 *
 * @return 0 when the program finishes successfully.
 */
/*******  ece73af0-7538-4f1a-a8cb-29ed96fc4e04  *******/
int main()
{
    // --- build a door and its parts
    Motor motor = Motor(Motor::BACKWARD);
    PushButton do_close = PushButton(PushButton::PUSHBUTTON_RELEASED);
    PushButton do_open = PushButton(PushButton::PUSHBUTTON_RELEASED);
    LightBarrier closed_position = LightBarrier(LightBarrier::LIGHTBARRIER_BEAM_BROKEN);
    LightBarrier opened_position= LightBarrier(LightBarrier::LIGHTBARRIER_BEAM_SOLID);
    Door door = Door(&motor, &do_close, &do_open, &closed_position, &opened_position);


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
