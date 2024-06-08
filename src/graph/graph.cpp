#include "graph.h"
#include <algorithm>

Graph::Graph() {}

Graph::~Graph()
{
    clear();
}

void Graph::addNode(int id)
{
    if (!getNode(id))
    {
        nodes.emplace_back(std::make_shared<GraphNode>(id));
    }
}

void Graph::removeNode(int id)
{
    auto it = std::find_if(nodes.begin(), nodes.end(), [id](const auto &node)
                           { return node->getId() == id; });
    if (it != nodes.end())
    {
        nodes.erase(it);
    }
}

void Graph::addEdge(int src, int dest, int weight)
{
    auto srcNode = getNode(src);
    auto destNode = getNode(dest);
    if (srcNode && destNode)
    {
        auto edge = std::make_shared<GraphEdge>(srcNode, destNode, weight);
        srcNode->addEdge(edge);
    }
}

void Graph::removeEdge(int src, int dest)
{
    auto srcNode = getNode(src);
    if (srcNode)
    {
        srcNode->removeEdge(dest);
    }
}

std::shared_ptr<GraphNode> Graph::getNode(int id)
{
    auto it = std::find_if(nodes.begin(), nodes.end(), [id](const auto &node)
                           { return node->getId() == id; });
    return it != nodes.end() ? *it : nullptr;
}

std::vector<std::shared_ptr<GraphNode>> Graph::getNodes()
{
    return nodes;
}

void Graph::clear()
{
    nodes.clear();
}