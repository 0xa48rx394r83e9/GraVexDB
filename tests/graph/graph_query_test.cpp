#include "graph.h"
#include "graph_query.h"
#include <cassert>
#include <iostream>

void testGraphQuery()
{
    auto graph = std::make_shared<Graph>();

    // Create a sample graph
    graph->addNode(1);
    graph->addNode(2);
    graph->addNode(3);
    graph->addNode(4);
    graph->addEdge(1, 2, 1);
    graph->addEdge(1, 3, 1);
    graph->addEdge(2, 4, 1);

    // Test getNeighbors query
    auto neighbors = GraphQuery::getNeighbors(graph, 1);
    assert(neighbors.size() == 2);
    assert(neighbors[0]->getId() == 2);
    assert(neighbors[1]->getId() == 3);

    // Test getShortestPath query
    auto shortestPath = GraphQuery::getShortestPath(graph, 1, 4);
    assert(shortestPath.size() == 3);
    assert(shortestPath[0]->getId() == 1);
    assert(shortestPath[1]->getId() == 2);
    assert(shortestPath[2]->getId() == 4);
}

int main()
{
    testGraphQuery();
    std::cout << "Graph query tests passed!" << std::endl;
    return 0;
}