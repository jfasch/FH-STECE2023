#pragma once

#include "motor.h"

class MotorMock : public Motor {
public:
    MotorMock(Direction direction);  // ✅ Nur Deklaration

    void forward() override;
    void backward() override;
    void stop() override;
    Direction get_direction() const override;

private:
    Direction _direction;
};
