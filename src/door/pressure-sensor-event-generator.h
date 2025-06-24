#pragma once
#include "pressure-sensor.h"
#include "pressure-sensor-enums.h"

class PressureSensorEventGenerator
{
    public:
        enum PressureSensorEvent
        {
            NORMAL_PRESSURE,
            UNDER_PRESSURE,
            OVER_PRESSURE,
            PRESSURE_SENSOR_ERROR,
        };
        PressureSensorEventGenerator(PressureSensor* sensor, 
                                     float under_pressure = 0.0f, 
                                     float over_pressure = 0.0f);
        PressuerSensorEvent get_event() const;
    private:
        PressureSensor* _sensor;
        float _under_pressure;
        float _over_pressure;
};