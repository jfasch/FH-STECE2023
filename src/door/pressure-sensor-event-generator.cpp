#include "pressure-sensor-event-generator.h"
#include "pressure-sensor.h"

PressureSensorEventGenerator::PressureSensorEventGenerator(PressureSensor* sensor, 
                                                           float under_pressure, 
                                                           float over_pressure
                                                        )
{
    this->_sensor = sensor;
    this->_under_pressure = under_pressure;
    this->_over_pressure = over_pressure;
}
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