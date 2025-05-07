#include "point.h"
#include <stdio.h>

point::point(int x, int y)
{
    this->_x = x;
    this->_y = y;
}

void point::print(const char* pfx) const
{
    printf("%s: (%d,%d)\n", pfx, this->_x, this->_y);
}

void point::move(struct point by)
{
    this->_x += by._x;
    this->_y += by._y;
}
