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
                                     float over_pressure = 0.0f,
                                     bool hysteresis_enabled = false,
                                     float hysteresis_value = 0.01f);

        // setters for hysteresis
        void enable_hysteresis(bool enable);
        void set_hysteresis_value(float value);

        // get_event updates internal state when hysteresis is enabled
        PressureSensorEvent get_event();
    private:
        PressureSensor* _sensor;
        float _under_pressure;
        float _over_pressure;
        
        // hysteresis configuration
        bool _hysteresis_enabled;
        float _hysteresis_value;

        // state for hysteresis behavior
        PressureSensorEvent _last_event;
        bool _initialized;
};