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
        MotorDirection direction;

    public: 
    Motor(MotorDirection direction);
    void forward();
    void backward();
    void stop();

    // for tests only
    MotorDirection get_direction() const;
};

//void Motor_init(Motor* self, MotorDirection direction);
//void Motor_forward(Motor* self);
//void Motor_backward(Motor* self);
//void Motor_stop(Motor* self);


