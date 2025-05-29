#include <door.h>
#include <motor.h>
#include <push-button.h>
#include <light-barrier.h>

#include <time.h>
#include <iostream>

int main()
{
    // --- Erstelle die Tür und ihre Komponenten
    Motor motor(Motor::Direction::IDLE);

    PushButton do_close(PushButton::State::RELEASED);
    PushButton do_open(PushButton::State::RELEASED);

    LightBarrier closed_position(LightBarrier::State::BEAM_BROKEN);  // Tür in "geschlossen" Position
    LightBarrier opened_position(LightBarrier::State::BEAM_SOLID);   // Tür nicht in "geöffnet" Position

    Door door(&motor, &do_close, &do_open, &closed_position, &opened_position);

    // --- Haupt-SPS-Schleife ausführen
    struct timespec interval = {
        .tv_sec = 0,
        .tv_nsec = 1000 * 1000,  // 1 Millisekunde
    };

    while (true) {
        door.check();  // Türlogik prüfen
        nanosleep(&interval, nullptr);  // Wartezeit
    }

    return 0;
}