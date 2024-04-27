#include "Way.h"
#include <cmath>

Way::Way(Point* p1, Point* p2) : start(p1), finish(p2)
{
    len = pow((pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2)), 0.5);
}

bool Way::operator<(const Way& obj) const
{
    return len < obj.len;
}
