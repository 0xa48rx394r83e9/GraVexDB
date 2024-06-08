#pragma once

#include <vector>
#include <memory>
#include "graph_node.h"
#include "graph_edge.h"

class Graph
{
public:
    Graph();
    ~Graph();

    void addNode(int id);
    void removeNode(int id);
    void addEdge(int src, int dest, int weight);
    void removeEdge(int src, int dest);

    std::shared_ptr<GraphNode> getNode(int id);
    std::vector<std::shared_ptr<GraphNode>> getNodes();

    void clear();

private:
    std::vector<std::shared_ptr<GraphNode>> nodes;
};