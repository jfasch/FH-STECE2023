#include "sensor1.h"

static void Sensor1_dtor(struct Sensor* sensor)
{
    // cleanup
}

static double Sensor1_get_value(struct Sensor* sensor)
{
    return 36.5;
}

void Sensor1_init(struct Sensor1* self)
{
    Sensor_init(&self->_base, Sensor1_get_value, Sensor1_dtor);
}

