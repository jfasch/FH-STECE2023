#include "sensor2.h"

static void Sensor2_dtor(struct Sensor* self)
{
    // cleanup
}

static double Sensor2_get_value(struct Sensor* self)
{
    return 42.3;
}

void Sensor2_init(struct Sensor2* self)
{
    Sensor_init(&self->_base, Sensor2_get_value, Sensor2_dtor);
}
