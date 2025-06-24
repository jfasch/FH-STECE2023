#include "pressure-sensor-event-generator.h"

PressureSensorEventGenerator::PressureSensorEventGenerator(PressureSensor* sensor, 
                                                           float under_pressure, 
                                                           float over_pressure
                                                        )
{
    this->_sensor = sensor;
    this->_under_pressure = under_pressure;
    this->_over_pressure = over_pressure;
}
PressureSensorEvent PressureSensorEventGenerator::get_event() const
{
    float pressure = _sensor->get_pressure();
    
    if (pressure < _under_pressure && pressure >= 0.0f) {
        return PressureSensorEvent::UNDER_PRESSURE;
    } else if (pressure > _over_pressure) {
        return PressureSensorEvent::OVER_PRESSURE;
    } else if (pressure >= 0.0f) {
        return PressureSensorEvent::NORMAL_PRESSURE;
    } else {
        return PressureSensorEvent::PRESSURE_SENSOR_ERROR;
    }
}