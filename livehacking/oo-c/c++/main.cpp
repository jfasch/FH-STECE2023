#include "sensor1.h"
#include "sensor2.h"
#include <iostream>
#include <unistd.h>

int main()
{
    Sensor1 s1;
    Sensor2 s2;
    Sensor* sensors[] = { &s1, &s2 };
    while (true) {
        for (int i=0; i<2; i++)
            std::cout << sensors[i]->get_value() << std::endl;
        sleep(1);
    }
    return 0;
}
