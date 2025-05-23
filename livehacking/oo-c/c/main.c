#include "sensor1.h"
#include "sensor2.h"
#include <stdio.h>
#include <unistd.h>

int main()
{
    struct Sensor1 s1;
    Sensor1_init(&s1);
    struct Sensor2 s2;
    Sensor2_init(&s2);
    struct Sensor* sensors[] = { (struct Sensor*)&s1, (struct Sensor*)&s2 };
    while (1) {
        for (int i=0; i<2; i++)
            printf("%lf\n", Sensor_get_value(sensors[i]));
        sleep(1);
    }
    return 0;
}
