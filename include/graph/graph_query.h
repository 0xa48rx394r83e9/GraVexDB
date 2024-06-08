#pragma once

#include <vector>
#include <memory>

class Graph;
class GraphNode;

class GraphQuery
{
public:
    static std::vector<std::shared_ptr<GraphNode>> getNeighbors(std::shared_ptr<Graph> graph, int nodeId);
    static std::vector<std::shared_ptr<GraphNode>> getShortestPath(std::shared_ptr<Graph> graph, int startNodeId, int endNodeId);

private:
    GraphQuery();
};