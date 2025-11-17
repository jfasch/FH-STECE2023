#pragma once

#include <door/input-switch.h>
#include <door/event-edge-detector.h>
#include <door/motor.h>
#include <door/analog-sensor-event-generator.h>

typedef struct input
{
    InputSwitch::State button_outside;
    InputSwitch::State button_inside;
    InputSwitch::State sensor_closed;
    InputSwitch::State sensor_open;
    AnalogSensorEvent analogsensor;

}input_t;

typedef struct events
{
    EdgeDetector::State open_button_pressed;
    EdgeDetector::State close_button_pressed;
    EdgeDetector::State light_barrier_closed;
    EdgeDetector::State light_barrier_open;
    AnalogSensorEvent analog_state;

}events_t;

typedef struct output
{
    Motor::Direction motor_direction;
    // Display?
}output_t;
