// TEST either with motorLED or motorStepper (--stepper, --led), defaults to motorLED
#include "../src/door/motorLED.h"
#include "../src/door/output-switch-gpio.h"
#include "../src/door/motorStepper.h
#include "../src/door/motor.h"

int main(int argc, char const *argv[])
{
    
    Motor* motor;
    if("--led" == std::string(argv[1]))
    {
        motor= new MotorLED(
            *(new OutputSwitchGPIO("/dev/gpiochip0", 20)),
            *(new OutputSwitchGPIO("/dev/gpiochip0", 21))
        );
    }
    else if("--stepper" == std::string(argv[1]))
    {
        //Defaulting MotorLED while refactoring motorStepper
        //todo implement motorStepper test
        motor = new MotorLED(
            *(new OutputSwitchGPIO("/dev/gpiochip0", 20)),
            *(new OutputSwitchGPIO("/dev/gpiochip0", 21))
        );

    }else
    {
        motor = new MotorLED(  
            *(new OutputSwitchGPIO("/dev/gpiochip0", 20)),
            *(new OutputSwitchGPIO("/dev/gpiochip0", 21))
        );
    }


    return 0;
}

int forward_test(Motor* motor)
{
    motor->forward();
    sleep(2);
    return 0;
}

int backward_test(Motor* motor)
{
    motor->backward();
    sleep(2);
    return 0;
}

int stop_test(Motor* motor)
{   
    motor->stop();
    sleep(2);
    return 0;
}   