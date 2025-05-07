#ifndef point_h
#define point_h

struct point
{
    int x;
    int y;
};

void point_init(struct point* this, int x, int y);
void point_print(const struct point* this, char* pfx);
void point_move(struct point* this, struct point by);

#endif
