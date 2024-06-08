#include "graph.h"
#include "graph_traversal.h"
#include <cassert>
#include <iostream>

void testGraphTraversal()
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

    // Test BFS traversal
    auto bfsResult = GraphTraversal::BFS(graph, 1);
    assert(bfsResult.size() == 4);
    assert(bfsResult[0]->getId() == 1);
    assert(bfsResult[1]->getId() == 2);
    assert(bfsResult[2]->getId() == 3);
    assert(bfsResult[3]->getId() == 4);

    // Test DFS traversal
    auto dfsResult = GraphTraversal::DFS(graph, 1);
    assert(dfsResult.size() == 4);
    assert(dfsResult[0]->getId() == 1);
    assert(dfsResult[1]->getId() == 2);
    assert(dfsResult[2]->getId() == 4);
    assert(dfsResult[3]->getId() == 3);
}

int main()
{
    testGraphTraversal();
    std::cout << "Graph traversal tests passed!" << std::endl;
    return 0;
}