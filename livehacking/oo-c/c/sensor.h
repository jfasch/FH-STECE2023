#pragma once

// class Sensor
// {
// public:
//     virtual ~Sensor() = default;
//     virtual double get_value() = 0;
// };

struct Sensor;

typedef double (*get_value_func)(struct Sensor* self);
typedef void (*dtor_func)(struct Sensor* self);

struct Sensor
{
    dtor_func dtor;
    get_value_func get_value;
};

void Sensor_init(struct Sensor* sensor, get_value_func, dtor_func);
void Sensor_deinit(struct Sensor* sensor);
double Sensor_get_value(struct Sensor* sensor);
