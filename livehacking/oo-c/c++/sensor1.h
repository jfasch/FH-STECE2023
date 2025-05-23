#pragma once

#include "sensor.h"

class Sensor1 : public Sensor
{
public:
    double get_value() override;
};
