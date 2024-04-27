#include <iostream>
#include <fstream>
#include <algorithm>
#include "Graph.h"

std::ostream& operator<<(std::ostream& os, const Graph& Graph) {
    for (int i = 0; i < Graph.minimal_tree.size(); i++)
    {
        os << " " << Graph.minimal_tree[i].start->id << " <-----> " << Graph.minimal_tree[i].finish->id << " " << std::endl;
    };
    return os;
};

int main()
{
    std::string name;
    std::cin >> name;

    Graph myGraph = Graph(name);

    myGraph.create_minimal_tree();

    std::cout << myGraph;

    std::cout << (myGraph.create_minimal_tree() == true) << std::endl;

    return 0;
}