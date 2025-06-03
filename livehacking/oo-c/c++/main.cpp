#include "interface.h"
#include "implementation1.h"
#include "implementation2.h"

int main()
{
    Implementation1 impl1{42};
    Implementation2 impl2{"hello"};

    Interface* objects[] = { &impl1, &impl2 };
    for (int i=0; i<2; i++)
        objects[i]->method();

    return 0;
}
