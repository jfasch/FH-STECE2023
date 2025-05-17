#pragma once


enum MotorDirection
{
    MOTOR_IDLE,
    MOTOR_FORWARD,
    MOTOR_BACKWARD,
};

class Motor 
{
    private: 
    MotorDirection _direction;
    
    public:
    // Konstruktor
    Motor( MotorDirection direction = MOTOR_IDLE);
    
    // Methoden
    void forward ();
    void backward ();
    void stop();

    // Getter
    MotorDirection direction() const;

};