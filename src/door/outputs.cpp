#include "outputs.h"
#include <door/motor.h>

Outputs::Outputs(Motor* motor)
{
    _motor = motor;
}

void Outputs::set_outputs(const output_t out)
{
    if (out.motor_forward)
    {
        _motor->forward();
    }
    if (out.motor_backward)
    {
        _motor->backward();
    }
    if (out.motor_stop)
    {
        _motor->stop();
    }
}