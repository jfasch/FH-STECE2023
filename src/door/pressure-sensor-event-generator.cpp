#include "pressure-sensor-event-generator.h"

PressureSensorEventGenerator::PressureSensorEventGenerator(PressureSensor* sensor, 
                                                           float under_pressure, 
                                                           float over_pressure,
                                                           bool hysteresis_enabled,
                                                           float hysteresis_value)
{
    this->_sensor = sensor;
    this->_under_pressure = under_pressure;
    this->_over_pressure = over_pressure;

    this->_hysteresis_enabled = hysteresis_enabled;
    this->_hysteresis_value = hysteresis_value;

    this->_initialized = false;
    this->_last_event = PressureSensorEvent::NORMAL_PRESSURE;
}

void PressureSensorEventGenerator::enable_hysteresis(bool enable)
{
    this->_hysteresis_enabled = enable;
}

void PressureSensorEventGenerator::set_hysteresis_value(float value)
{
    this->_hysteresis_value = value;
}

PressureSensorEvent PressureSensorEventGenerator::get_event()
{
    float pressure = _sensor->get_pressure();

    // Immediate sensor error (no hysteresis)
    if (pressure < 0.0f) {
        _last_event = PressureSensorEvent::PRESSURE_SENSOR_ERROR;
        _initialized = true;
        return _last_event;
    }

    // If hysteresis is disabled or not yet initialized: behave as before and initialize state
    if (!_hysteresis_enabled || !_initialized) {
        if (pressure < _under_pressure && pressure >= 0.0f) {
            _last_event = PressureSensorEvent::UNDER_PRESSURE;
        } else if (pressure > _over_pressure) {
            _last_event = PressureSensorEvent::OVER_PRESSURE;
        } else if (pressure >= 0.0f) {
            _last_event = PressureSensorEvent::NORMAL_PRESSURE;
        } else {
            _last_event = PressureSensorEvent::PRESSURE_SENSOR_ERROR;
        }
        _initialized = true;
        return _last_event;
    }

    // Hysteresis enabled and initialized: use margin logic per state
    float h = _hysteresis_value;

    switch (_last_event) {
        case PressureSensorEvent::OVER_PRESSURE:
            // stay in OVER unless we have fallen below (over - h)
            if (pressure <= (_over_pressure - h)) {
                // now evaluate whether under or normal
                if (pressure < (_under_pressure - h)) {
                    _last_event = PressureSensorEvent::UNDER_PRESSURE;
                } else if (pressure > (_over_pressure + h)) {
                    _last_event = PressureSensorEvent::OVER_PRESSURE;
                } else {
                    _last_event = PressureSensorEvent::NORMAL_PRESSURE;
                }
            } else {
                // remain OVER
                _last_event = PressureSensorEvent::OVER_PRESSURE;
            }
            break;

        case PressureSensorEvent::UNDER_PRESSURE:
            // stay in UNDER unless we have risen above (under + h)
            if (pressure >= (_under_pressure + h)) {
                if (pressure > (_over_pressure + h)) {
                    _last_event = PressureSensorEvent::OVER_PRESSURE;
                } else if (pressure < (_under_pressure - h)) {
                    _last_event = PressureSensorEvent::UNDER_PRESSURE;
                } else {
                    _last_event = PressureSensorEvent::NORMAL_PRESSURE;
                }
            } else {
                // remain UNDER
                _last_event = PressureSensorEvent::UNDER_PRESSURE;
            }
            break;

        case PressureSensorEvent::NORMAL_PRESSURE:
        default:
            // require crossing thresholds with hysteresis to change state
            if (pressure > (_over_pressure + h)) {
                _last_event = PressureSensorEvent::OVER_PRESSURE;
            } else if (pressure < (_under_pressure - h)) {
                _last_event = PressureSensorEvent::UNDER_PRESSURE;
            } else {
                _last_event = PressureSensorEvent::NORMAL_PRESSURE;
            }
            break;
    }

    return _last_event;
}