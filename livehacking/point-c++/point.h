#ifndef point_h
#define point_h

class point
{
private:
    int _x;
    int _y;

public:
    point(int x, int y);
    void print(const char* pfx) const;
    void move(struct point by);

    // inline access methods
    int x() const { return _x; }
    int y() const { return _y; }
};

#endif
