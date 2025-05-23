#include "sensor.h"

void Sensor_init(struct Sensor* sensor, get_value_func get_value, dtor_func dtor)
{
    sensor->get_value = get_value;
    sensor->dtor = dtor;
}

void Sensor_deinit(struct Sensor* sensor)
{
    sensor->dtor(sensor);
}

double Sensor_get_value(struct Sensor* sensor)
{
    return sensor->get_value(sensor);
}
