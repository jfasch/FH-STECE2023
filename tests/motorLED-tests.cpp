#include <door/motorLED.h>
#include <unistd.h>

int main(){

    MotorLED motorled("/dev/gpioip0", 20, 21, Motor::Direction::IDLE);

    Motor* motor = &motorled;
    motor->forward();
    sleep(2);

    motor->backward();
    sleep(2);

    motor->stop();
    sleep(2);

}