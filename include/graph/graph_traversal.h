#pragma once

#include <vector>
#include <memory>

class Graph;
class GraphNode;

class GraphTraversal
{
public:
    static std::vector<std::shared_ptr<GraphNode>> BFS(std::shared_ptr<Graph> graph, int startNodeId);
    static std::vector<std::shared_ptr<GraphNode>> DFS(std::shared_ptr<Graph> graph, int startNodeId);

    void DFSHelper(std::shared_ptr<GraphNode> node, std::unordered_set<int> &visited, std::vector<std::shared_ptr<GraphNode>> &result);

private:
    GraphTraversal();
};