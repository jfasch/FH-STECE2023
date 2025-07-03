#pragma once
#include <door/event-edge-detector.h>
#include <door/motor.h>
#include <door/input-switch.h>
typedef struct input
{
    InputSwitch::State sensor_closed;
    InputSwitch::State sensor_opened;
    InputSwitch::State button_outside;
    InputSwitch::State button_inside;
    // TODO: PressureSensor Inputs
}input_t;

typedef struct events
{
    EdgeDetector::State open_button_pressed;
    EdgeDetector::State close_button_pressed;
    EdgeDetector::State light_barrier_1_reached;
    EdgeDetector::State light_barrier_2_reached;
    // TODO: PressureSensor Events

}events_t;

typedef struct output
{
    Motor::Direction motor_direction;
    // Display?
}output_t;
