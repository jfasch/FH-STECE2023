#include "point.h"
#include <iostream>

int main(void)
{
    point p1(1, 2);
    point p2(42, 7);

    p1.print("point p1");
    p2.print("point p2");

    p1.move(p2);

    p1.print("moved p1");

    std::cout << p1.x() << ',' << p1.y() << '\n';

    return 0;
}
