#include "graph.h"
#include <cassert>

void testGraphOperations()
{
    auto graph = std::make_shared<Graph>();

    // Test adding nodes
    graph->addNode(1);
    graph->addNode(2);
    graph->addNode(3);
    assert(graph->getNodes().size() == 3);

    // Test adding edges
    graph->addEdge(1, 2, 1);
    graph->addEdge(2, 3, 1);
    assert(graph->getNode(1)->getEdges().size() == 1);
    assert(graph->getNode(2)->getEdges().size() == 2);

    // Test removing nodes
    graph->removeNode(2);
    assert(graph->getNodes().size() == 2);
    assert(graph->getNode(1)->getEdges().size() == 0);

    // Test removing edges
    graph->addEdge(1, 3, 1);
    graph->removeEdge(1, 3);
    assert(graph->getNode(1)->getEdges().size() == 0);
}

int main()
{
    testGraphOperations();
    std::cout << "Graph tests passed!" << std::endl;
    return 0;
}