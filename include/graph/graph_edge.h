#pragma once

#include <memory>

class GraphNode;

class GraphEdge
{
public:
    GraphEdge(std::shared_ptr<GraphNode> src, std::shared_ptr<GraphNode> dest, int weight);
    ~GraphEdge();

    std::shared_ptr<GraphNode> getSource();
    std::shared_ptr<GraphNode> getDestination();
    int getWeight() const;

private:
    std::shared_ptr<GraphNode> source;
    std::shared_ptr<GraphNode> destination;
    int weight;
};