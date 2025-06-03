#include <iostream>
#include <vector>

class Sensor
{
public:
    virtual ~Sensor() = default;
    virtual double get_value() const = 0;
};

class YourSensor : public Sensor
{
public:
    YourSensor(double value) : _value{value} {}
    double get_value() const override
    {
        std::cout << "YourSensor::get_value(): " << _value << std::endl;
        return _value;
    }
private:
    double _value;
};

class MySensor : public Sensor
{
public:
    MySensor(double base, double correction)
    : _base{base},
      _correction{correction} {}

    double get_value() const override
    {
        double value = _base + _correction;
        std::cout << "MySensor::get_value(): " << value << std::endl;
        return value;
    }
private:
    double _base;
    double _correction;
};

class HerSensor : public Sensor
{
public:
    HerSensor(double value) : _value(value) {}
    double get_value() const override
    {
        std::cout << "HerSensor::get_value(): " << _value + 1000 << std::endl;
        return _value + 1000;
    }
private:
    double _value;
};

class DeppertSensor : public Sensor
{
public:
    DeppertSensor(double value)
    {
        _value = new double;
        *_value = value;
    }
    ~DeppertSensor() override
    {
        delete _value;
    }

    double get_value() const override
    {
        return *_value;
    }

private:
    double* _value;
};

double avg(std::vector<Sensor*> sensors)
{
    double retavg = 0;
    unsigned count = 0;
    for (const Sensor* sensor: sensors) {
        count++;
        retavg += sensor->get_value();
    }
    return retavg / count;
}

int main()
{
    std::vector<Sensor*> sensors = { 
        new MySensor{42.5, 0.666},
        new MySensor{35.2, 42.666},
        new HerSensor{666},
        new YourSensor{42},
        new DeppertSensor{42.666},
    };

    std::cout << avg(sensors) << std::endl;

    for (Sensor* sensor: sensors)
        delete sensor;

    return 0;
}
