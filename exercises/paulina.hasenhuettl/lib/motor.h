#pragma once 

enum class MotorDirection
{
    IDLE,
    FORWARD,
    BACKWARD,
};

class Motor
{
    public:
        Motor(MotorDirection direction = MotorDirection::IDLE);

        void forward();
        void backward();
        void stop();
    
        MotorDirection get_direction() const; //for testing only


    private:
        MotorDirection _direction;
};


/*
#pragma once


enum MotorDirection
{
    MOTOR_IDLE,
    MOTOR_FORWARD,
    MOTOR_BACKWARD,
};

struct Motor
{
    MotorDirection direction;
};

void Motor_init(Motor* self, MotorDirection direction);
void Motor_forward(Motor* self);
void Motor_backward(Motor* self);
void Motor_stop(Motor* self);

// for tests only
MotorDirection Motor_get_direction(Motor* self);
*/