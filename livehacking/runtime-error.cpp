#include <stdexcept>

void foo()
{
    throw std::runtime_error("file nix open");
}

int main()
{
    foo();
    return 0;
}
