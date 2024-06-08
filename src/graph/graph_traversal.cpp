#include "graph_traversal.h"
#include "graph.h"
#include <queue>
#include <unordered_set>

std::vector<std::shared_ptr<GraphNode>> GraphTraversal::BFS(std::shared_ptr<Graph> graph, int startNodeId)
{
    std::vector<std::shared_ptr<GraphNode>> result;
    std::unordered_set<int> visited;
    std::queue<std::shared_ptr<GraphNode>> queue;

    auto startNode = graph->getNode(startNodeId);
    if (!startNode)
    {
        return result;
    }

    visited.insert(startNodeId);
    queue.push(startNode);

    while (!queue.empty())
    {
        auto node = queue.front();
        queue.pop();
        result.push_back(node);

        for (const auto &edge : node->getEdges())
        {
            auto neighbor = edge->getDestination();
            if (visited.find(neighbor->getId()) == visited.end())
            {
                visited.insert(neighbor->getId());
                queue.push(neighbor);
            }
        }
    }

    return result;
}

std::vector<std::shared_ptr<GraphNode>> GraphTraversal::DFS(std::shared_ptr<Graph> graph, int startNodeId)
{
    std::vector<std::shared_ptr<GraphNode>> result;
    std::unordered_set<int> visited;

    auto startNode = graph->getNode(startNodeId);
    if (!startNode)
    {
        return result;
    }

    DFSHelper(startNode, visited, result);

    return result;
}

void GraphTraversal::DFSHelper(std::shared_ptr<GraphNode> node, std::unordered_set<int> &visited,
                               std::vector<std::shared_ptr<GraphNode>> &result)
{
    visited.insert(node->getId());
    result.push_back(node);

    for (const auto &edge : node->getEdges())
    {
        auto neighbor = edge->getDestination();
        if (visited.find(neighbor->getId()) == visited.end())
        {
            DFSHelper(neighbor, visited, result);
        }
    }
}