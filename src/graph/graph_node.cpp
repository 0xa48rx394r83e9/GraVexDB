#include "graph_node.h"
#include <algorithm>

GraphNode::GraphNode(int id) : id(id) {}

GraphNode::~GraphNode()
{
    edges.clear();
}

int GraphNode::getId() const
{
    return id;
}

void GraphNode::addEdge(std::shared_ptr<GraphEdge> edge)
{
    edges.push_back(edge);
}

void GraphNode::removeEdge(int destId)
{
    auto it = std::find_if(edges.begin(), edges.end(), [destId](const auto &edge)
                           { return edge->getDestination()->getId() == destId; });
    if (it != edges.end())
    {
        edges.erase(it);
    }
}

std::vector<std::shared_ptr<GraphEdge>> GraphNode::getEdges()
{
    return edges;
}