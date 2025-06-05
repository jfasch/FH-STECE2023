#pragma once

enum class MotorDirection
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
        Motor(MotorDirection direction);

        void Motor_forward();
        void Motor_backward();
        void Motor_stop();
        
        // for tests only
        MotorDirection get_direction() const {return _direction;};
};

