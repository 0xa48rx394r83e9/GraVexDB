#include "graph_edge.h"
#include "graph_node.h"

GraphEdge::GraphEdge(std::shared_ptr<GraphNode> src, std::shared_ptr<GraphNode> dest, int weight)
    : source(src), destination(dest), weight(weight) {}

GraphEdge::~GraphEdge() {}

std::shared_ptr<GraphNode> GraphEdge::getSource()
{
    return source;
}

std::shared_ptr<GraphNode> GraphEdge::getDestination()
{
    return destination;
}

int GraphEdge::getWeight() const
{
    return weight;
}