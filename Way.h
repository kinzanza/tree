#pragma once
#ifndef WAY_H
#define WAY_H

#include "Point.h"
#include <cmath>

struct Way
{
    Point* start;
    Point* finish;
    double len;

    Way(Point* p1, Point* p2);

    bool operator<(const Way& obj) const;
};

#endif // WAY_H
