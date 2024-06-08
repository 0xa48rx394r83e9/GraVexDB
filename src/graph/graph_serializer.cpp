#include "graph_serializer.h"
#include "graph.h"
#include <fstream>

void GraphSerializer::serialize(std::shared_ptr<Graph> graph, const std::string &filename)
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file for writing: " + filename);
    }

    // Write the number of nodes
    file << graph->getNodes().size() << std::endl;

    // Write each node and its edges
    for (const auto &node : graph->getNodes())
    {
        file << node->getId() << std::endl;
        file << node->getEdges().size() << std::endl;
        for (const auto &edge : node->getEdges())
        {
            file << edge->getDestination()->getId() << " " << edge->getWeight() << std::endl;
        }
    }

    file.close();
}

std::shared_ptr<Graph> GraphSerializer::deserialize(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file for reading: " + filename);
    }

    auto graph = std::make_shared<Graph>();

    // Read the number of nodes
    size_t numNodes;
    file >> numNodes;

    // Read each node and its edges
    for (size_t i = 0; i < numNodes; ++i)
    {
        int nodeId;
        file >> nodeId;
        graph->addNode(nodeId);

        size_t numEdges;
        file >> numEdges;
        for (size_t j = 0; j < numEdges; ++j)
        {
            int destId, weight;
            file >> destId >> weight;
            graph->addEdge(nodeId, destId, weight);
        }
    }

    file.close();

    return graph;
}