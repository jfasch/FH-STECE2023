#include <stdlib.h>
#include <iostream>

// #define NULL (0)
// #define NULL ((void*)0)


void foo(int)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void foo(void*)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int main()
{
    foo(NULL);
    return 0;
}
