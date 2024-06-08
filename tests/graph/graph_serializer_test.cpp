#include "graph.h"
#include "graph_serializer.h"
#include <cassert>
#include <iostream>

void testGraphSerializer()
{
    auto graph = std::make_shared<Graph>();

    // Create a sample graph
    graph->addNode(1);
    graph->addNode(2);
    graph->addNode(3);
    graph->addEdge(1, 2, 1);
    graph->addEdge(2, 3, 1);

    // Test serialization
    GraphSerializer::serialize(graph, "graph.txt");

    // Test deserialization
    auto deserializedGraph = GraphSerializer::deserialize("graph.txt");
    assert(deserializedGraph->getNodes().size() == 3);
    assert(deserializedGraph->getNode(1)->getEdges().size() == 1);
    assert(deserializedGraph->getNode(2)->getEdges().size() == 2);
    assert(deserializedGraph->getNode(3)->getEdges().size() == 1);
}

int main()
{
    testGraphSerializer();
    std::cout << "Graph serializer tests passed!" << std::endl;
    return 0;
}