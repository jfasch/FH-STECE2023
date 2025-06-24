#pragma once
#include "pressure-sensor.h"
#include "pressure-sensor-enums.h"

class PressureSensorEventGenerator
{
    public:
        PressureSensorEventGenerator(PressureSensor* sensor, 
                                     float under_pressure = 0.0f, 
                                     float over_pressure = 0.0f);
        PressuerSensorEvent get_event() const;
    private:
        PressureSensor* _sensor;
        float _under_pressure;
        float _over_pressure;
};