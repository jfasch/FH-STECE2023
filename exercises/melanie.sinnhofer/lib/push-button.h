#pragma once



class PushButton
{
public:
    enum class State   //PushButton::State::PRESSED
    {
        PRESSED,
        RELEASED,
    };


    explicit PushButton(State state);  // Syntax: explicit NameOfConstructorIdentischMitNameOfClass (ParameterTypeState TypeStateWithNamestate);

    State get_state() const;

    // for tests only
    void set_state(State state);


private:

    State state_;
};

