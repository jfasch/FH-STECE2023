#include "point.h"

int main(void)
{
    struct point p1;
    point_init(&p1, 1, 2);

    struct point p2;
    point_init(&p2, 42, 7);
    
    point_print(&p1, "point p1");
    point_print(&p2, "point p2");

    point_move(&p1, p2);

    point_print(&p1, "moved p1");

    return 0;
}
