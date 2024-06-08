#pragma once

#include <vector>
#include <memory>
#include "graph_edge.h"

class GraphNode
{
public:
    GraphNode(int id);
    ~GraphNode();

    int getId() const;
    void addEdge(std::shared_ptr<GraphEdge> edge);
    void removeEdge(int destId);
    std::vector<std::shared_ptr<GraphEdge>> getEdges();

private:
    int id;
    std::vector<std::shared_ptr<GraphEdge>> edges;
};