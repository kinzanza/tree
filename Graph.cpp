#include "Graph.h"
#include <fstream>
#include <algorithm>
#include <iostream>

Graph::Graph() = default;

Graph::Graph(std::string filename)
{
    std::ifstream inFile(filename);

    if (!inFile)
    {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }

    double first, second;
    int id;

    while (inFile >> id >> first >> second)
    {
        Point* point = new Point(id, first, second);
        points_list.push_back(point);
    }

    inFile.close();

    // Создание путей между точками
    for (size_t i = 0; i < points_list.size(); ++i)
    {
        for (size_t j = i + 1; j < points_list.size(); ++j)
        {
            if (points_list[i]->id != points_list[j]->id)
            {
                ways_list.push_back(Way(points_list[i], points_list[j]));
            }
        }
    }
}

void Graph::recolor(int color1, int color2)
{
    for (Point* point : points_list)
    {
        if (point->color == color1)
        {
            point->color = color2;
        }
    }
}

bool Graph::create_minimal_tree()
{
    int last_color = 1;
    int num_colors = 1;

    std::sort(ways_list.begin(), ways_list.end());

    for (Way new_way : ways_list)
    {
        if (new_way.finish->color == new_way.start->color && new_way.finish->color != 0) {}

        else if (new_way.start->color != 0 && new_way.finish->color != 0 && new_way.start->color != new_way.finish->color)
        {
            recolor(new_way.start->color, new_way.finish->color);
            num_colors -= 1;
            minimal_tree.push_back(new_way);
        }

        else if (new_way.start->color != 0)
        {
            new_way.finish->color = new_way.start->color;
            minimal_tree.push_back(new_way);
        }

        else if (new_way.finish->color != 0)
        {
            new_way.start->color = new_way.finish->color;
            minimal_tree.push_back(new_way);
        }

        else if (new_way.finish->color == 0 && new_way.start->color == 0)
        {
            new_way.finish->color = last_color;
            new_way.start->color = last_color;
            last_color += 1;
            num_colors += 1;
            minimal_tree.push_back(new_way);
        }

        if (num_colors == 1)
        {
            return true;
        }
    }
    return false;
}
