#include <door/door.h>
#include <door/structs.h>
#include <door/inputs.h>
#include <door/pressure-sensor.h>
#include <door/pressure-sensor-event-generator.h>
#include <door/outputs.h>
#include <door/motor-mock.h>
#include <door/input-switch-mock.h>
#include <door/pressure-sensor-mock.h>
#include <door/timespec.h>

#include <door/input-switch.h>
#include <door/output-switch.h>

#include <door/input-switch-gpio-sysfs.h>
#include <door/pressure-sensor-bmp280.h>
#include <door/motor-stepper.h>

#include <string>
#include <iostream>
#include <signal.h>

// quit flag with atomic type
static volatile sig_atomic_t quit = 0;

// hander function to set quit flag
static void handler(int signal)
{
    if (signal == SIGTERM || signal == SIGINT)
        quit = 1;
}

int main(int argc, char** argv)
{
    // test flag
    [[maybe_unused]] int test = 0;

    // too many arguments
    if (argc > 2)
    {
        std::cout << "Error: Too many arguments!" << std::endl;
        std::cout << "Usage: ./run-door [--test]" << std::endl;
        
        return 1;
    }

    // one additional argument
    if (argc == 2)
    {
        std::string flag = argv[1];
        if (flag == "--test")
        {
            test = 1;
            std::cout << "Info: Test run, only using mock sensors." << std::endl;
        }
        else
        {
            std::cout << "Error: Invalide argument!" << std::endl;
            std::cout << "Usage: ./run-door [--test]" << std::endl;

            return 1;
        }
    }

    // event handler for SIGTERM and SIGINT
    struct sigaction sa = { 0 };
    sa.sa_handler = handler;

    int rv = sigaction(SIGTERM, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction(SIGTERM)");
        return 1;
    }
    rv = sigaction(SIGINT, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction(SIGINT)");
        return 1;
    }

    // create door
    Door door;

    InputSwitch*    button1 = nullptr;
    InputSwitch*    button2 = nullptr;
    InputSwitch*    light1 = nullptr;
    InputSwitch*    light2 = nullptr;

    PressureSensor* pressureSensor = nullptr;
    PressureSensorEventGenerator*   pressureSensorEG = nullptr;
    
    Motor*  motor = nullptr;

    TimeSpec time;

    if(test == 1)
    {
        // create sensors
        button1 = new InputSwitchMock(InputSwitch::State::INPUT_LOW);
        button2 = new InputSwitchMock(InputSwitch::State::INPUT_LOW);
        light1  = new InputSwitchMock(InputSwitch::State::INPUT_LOW);
        light2  = new InputSwitchMock(InputSwitch::State::INPUT_HIGH);

        // Pressure Sensor
        pressureSensor = new BMP280("/dev/i2c-1", 0x76);
        // Pressure Sensor Event Generator
        pressureSensorEG = new PressureSensorEventGenerator(pressureSensor);

        motor = new MotorMock(Motor::Direction::IDLE);
    }
    else
    {
        // create sensors
        button1 = new InputSwitchGPIOSysfs(17);
        button2 = new InputSwitchGPIOSysfs(27);
        light1  = new InputSwitchGPIOSysfs(22);
        light2  = new InputSwitchGPIOSysfs(23);

        // Pressure Sensor
        pressureSensor = new PressureSensorMock;
        // Pressure Sensor Event Generator
        pressureSensorEG = new PressureSensorEventGenerator(pressureSensor);

        motor = new MotorStepper("/dev/gpiochip0", 26, 17, "2000000", "1000000");
    }
    Inputs inputs(button1, button2, light1, light2, pressureSensorEG, time);
    Outputs outputs(motor);

    input_t in;
    events_t ev;
    output_t out;
    
    // get current inputs and create input struct
    in = inputs.get_inputs();

    // run door init and return output struct
    out = door.init(in);

    // set outputs
    outputs.set_outputs(out);

    // --- run main SPS loop
    auto interval = TimeSpec::from_milliseconds(1);

    while (!quit) // gracefull termination
    {
        // get current events and create event struct
        ev = inputs.get_events();

        // call door logic, and complain about cycle-time violation
        auto before = TimeSpec::now_monotonic();

        // run door cyclic and return output struct
        out = door.cyclic(ev);

        auto after = TimeSpec::now_monotonic();

        auto spent = after - before;
        if (spent > interval)
            std::cerr << "WARNING: door logic exceeds interval" << std::endl;

        // set outputs
        outputs.set_outputs(out);

        // suspend for the rest of the interval
        auto suspend = interval - spent;
        rv = nanosleep(&suspend, nullptr);
        if (rv == -1) {
            if (errno == EINTR)
                continue;
            else {
                perror("nanosleep");
                return 1;
            }
        }
    }

    // cleanup before exit
    // TODO: Nothing todo for now

    // Bye message
    std::cout << "Oh, I need to go, someone is calling me..." << std::endl;
    std::cout << "Bye, see you soon :)" << std::endl;
    std::cout << "I'll miss you <3" << std::endl;
    std::cout << "  -- yours, Depperte Door" << std::endl << std::endl;

    return 0;
}
