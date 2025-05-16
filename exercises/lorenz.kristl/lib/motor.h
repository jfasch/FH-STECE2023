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

#pragma once

class Motor
{
    public:
        enum class Direction
        {
            IDLE,
            FORWARD,
            BACKWARD,
        };

        Motor(Direction initialdirection = Direction::IDLE);

        void forward();
        void backward();
        void stop();

        Direction getDirection() const;
        
    private:
        Direction direction;
};