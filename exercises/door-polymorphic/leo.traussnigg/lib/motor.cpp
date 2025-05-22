class Motor {
public:
    virtual ~Motor() = default;

    // Start the motor
    virtual void start() = 0;

    // Stop the motor
    virtual void stop() = 0;

    // Set the speed of the motor (e.g., 0-100%)
    virtual void setSpeed(int percent) = 0;

    // Get the current speed of the motor
    virtual int getSpeed() const = 0;
};