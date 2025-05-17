#include "point.h"
#include <iostream>

int main(void)
{
    const point p(1, 2);
    p.print("point p");
    std::cout << p.x() << ',' << p.y() << '\n';
    return 0;
}
