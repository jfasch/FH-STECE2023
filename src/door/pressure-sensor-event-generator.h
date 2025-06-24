#pragma once
#include "pressure-sensor.h"

enum class PressureSensorEvent
{
    NORMAL_PRESSURE,
    UNDER_PRESSURE,
    OVER_PRESSURE,
    PRESSURE_SENSOR_ERROR,
};

class PressureSensorEventGenerator
{
    public:
        PressureSensorEventGenerator(PressureSensor* sensor, 
                                     float under_pressure = 0.0f, 
                                     float over_pressure = 0.0f);
        PressureSensorEvent get_event() const;
    private:
        PressureSensor* _sensor;
        float _under_pressure;
        float _over_pressure;
};