#pragma once
#ifndef POINT_H
#define POINT_H

struct Point
{
    int id;
    double x;
    double y;
    int color = 0;

    Point(int id, double x, double y);
};

#endif