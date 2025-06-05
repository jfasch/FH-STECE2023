#include "interface.h"
#include "implementation1.h"
#include "implementation2.h"

int main()
{
    struct Implementation1 impl1; // jjj ctor
    Implementation1_constructor(&impl1, 42);

    struct Implementation2 impl2; // jjj ctor
    Implementation2_constructor(&impl2, "hello");

    struct Interface* objects[] = { (struct Interface*)&impl1, (struct Interface*)&impl2 };
    for (int i=0; i<2; i++)
        objects[i]->method(objects[i]);

    for (int i=0; i<2; i++) // jjj dtor: **used only polymorphically,
                            // on interface**
        Interface_destructor(objects[i]);

    return 0;
}
