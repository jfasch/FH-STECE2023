#include "pressure-sensor-event-generator.h"

PressureSensorEventGenerator::PressureSensorEventGenerator(PressureSensor* sensor, 
                                                           float under_pressure, 
                                                           float over_pressure
                                                        );
PressuerSensorEvent::get_event() const
{
    float pressure = _sensor->get_pressure();
    
    if (pressure < _under_pressure) {
        return PressuerSensorEvent::UNDER_PRESSURE;
    } else if (pressure > _over_pressure) {
        return PressuerSensorEvent::OVER_PRESSURE;
    } else if (pressure >= 0.0f) {
        return PressuerSensorEvent::NORMAL_PRESSURE;
    } else {
        return PressuerSensorEvent::PRESSURE_SENSOR_ERROR;
    }
}