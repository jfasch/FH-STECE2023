#pragma once

#include "input-switch.h"
#include "event-edge-detector.h"
#include "motor.h"
#include "pressure-sensor-event-generator.h"

typedef struct input
{
    InputSwitch::State sensor_closed;
    InputSwitch::State sensor_opened;
    InputSwitch::State button_outside;
    InputSwitch::State button_inside;
    PressureSensorEvent pressuresensor;

}input_t;

typedef struct events
{
    EdgeDetector::State open_button_pressed;
    EdgeDetector::State close_button_pressed;
    EdgeDetector::State light_barrier_1_reached;
    EdgeDetector::State light_barrier_2_reached;
    PressureSensorEvent pressure_state;
    


}events_t;

typedef struct output
{
    Motor::Direction motor_direction;
    // Display?
}output_t;
