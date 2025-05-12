// motor.hpp
#pragma once

// Beibehaltung der ursprünglichen Enum-Definition
enum MotorDirection {
    MOTOR_IDLE,
    MOTOR_FORWARD,
    MOTOR_BACKWARD,
};

// C++-Klasse
class Motor {
public:
    // Konstruktor ersetzt Motor_init
    explicit Motor(MotorDirection dir = MOTOR_IDLE)
        : direction(dir) {}

    // Methoden statt freier Funktionen
    void forward()   { direction = MOTOR_FORWARD; }
    void backward()  { direction = MOTOR_BACKWARD; }
    void stop()      { direction = MOTOR_IDLE; }

    // Getter für Tests oder Statusabfrage
    MotorDirection getDirection() const { return direction; }

private:
    MotorDirection direction;
};


// for tests only
MotorDirection Motor_get_direction(Motor* self);
