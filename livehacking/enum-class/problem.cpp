enum class StateMachine1
{
    INIT,
    STATE1,
    STATE2,
};

enum class StateMachine2
{
    INIT,
    STATE3,
    STATE4,
};

int main()
{
    [[maybe_unused]] StateMachine1 state1 = StateMachine1::INIT;
    [[maybe_unused]] StateMachine2 state2 = StateMachine2::INIT;

    return 0;
}
