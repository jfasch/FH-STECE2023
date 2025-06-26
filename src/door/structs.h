#pragma once
#include <door/push-button.h>
#include <door/light-barrier.h>
#include <door/event-edge-detector.h>

typedef struct input
{
    LightBarrier::State sensor_closed;
    LightBarrier::State sensor_opened;
    PushButton::State button_outside;
    PushButton::State button_inside;
}input_t;

typedef struct events
{
    EdgeDetector::State open_button_pressed;
    EdgeDetector::State close_button_pressed;
    EdgeDetector::State light_barrier_1_reached;
    EdgeDetector::State light_barrier_2_reached;

}events_t;

typedef struct output
{
    bool motor_backward = false;
    bool motor_forward = false;
    bool motor_stop = false;
    bool display = false;
}output_t;