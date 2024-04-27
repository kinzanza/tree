#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include "Point.h"
#include "Way.h"

class Graph
{
public:
    std::vector<Point*> points_list;
    std::vector<Way> ways_list;
    std::vector<Way> minimal_tree;

    Graph();
    Graph(std::string filename);

    void recolor(int color1, int color2);
    bool create_minimal_tree();
};

#endif
