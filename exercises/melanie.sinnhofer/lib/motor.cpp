#include "motor.h"


// Konstruktor - wird automatisch aufgerufen bei Objekterstellung
Motor::Motor(Direction direction)
{
    direction_ = direction;
}

// Setzt Motor auf vorwärts
void Motor::forward()
{
    direction_ = Direction::FORWARD;
}

// Setzt Motor auf rückwärts  
void Motor::backward()
{
    direction_ = Direction::BACKWARD;
}

// Setzt Motor auf idle)
void Motor::stop()
{
    direction_ = Direction::IDLE;
}

// Get Methode - gibt aktuelle Richtung zurück
Motor::Direction Motor::get_direction() const
{
    return direction_;
}
