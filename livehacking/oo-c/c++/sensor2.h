#pragma once

#include "sensor.h"

class Sensor2 : public Sensor
{
public:
    double get_value() override;
};
