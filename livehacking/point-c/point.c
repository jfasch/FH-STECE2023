#include "point.h"
#include <stdio.h>

void point_init(struct point* this, int x, int y)
{
    this->x = x;
    this->y = y;
}

void point_print(const struct point* this, char* pfx)
{
    printf("%s: (%d,%d)\n", pfx, this->x, this->y);
}

void point_move(struct point* this, struct point by)
{
    this->x += by.x;
    this->y += by.y;
}
