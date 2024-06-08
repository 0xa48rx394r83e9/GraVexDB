#include "graph_query.h"
#include "graph.h"
#include <queue>
#include <unordered_map>
#include <unordered_set>

std::vector<std::shared_ptr<GraphNode>> GraphQuery::getNeighbors(std::shared_ptr<Graph> graph, int nodeId)
{
    std::vector<std::shared_ptr<GraphNode>> result;

    auto node = graph->getNode(nodeId);
    if (!node)
    {
        return result;
    }

    for (const auto &edge : node->getEdges())
    {
        result.push_back(edge->getDestination());
    }

    return result;
}

std::vector<std::shared_ptr<GraphNode>> GraphQuery::getShortestPath(std::shared_ptr<Graph> graph, int startNodeId, int endNodeId)
{
    std::vector<std::shared_ptr<GraphNode>> result;
    std::unordered_map<int, std::shared_ptr<GraphNode>> previous;
    std::unordered_set<int> visited;
    std::queue<std::shared_ptr<GraphNode>> queue;

    auto startNode = graph->getNode(startNodeId);
    auto endNode = graph->getNode(endNodeId);
    if (!startNode || !endNode)
    {
        return result;
    }

    visited.insert(startNodeId);
    queue.push(startNode);

    while (!queue.empty())
    {
        auto node = queue.front();
        queue.pop();

        if (node->getId() == endNodeId)
        {
            // Build the shortest path
            while (node)
            {
                result.push_back(node);
                node = previous[node->getId()];
            }
            std::reverse(result.begin(), result.end());
            break;
        }

        for (const auto &edge : node->getEdges())
        {
            auto neighbor = edge->getDestination();
            if (visited.find(neighbor->getId()) == visited.end())
            {
                visited.insert(neighbor->getId());
                previous[neighbor->getId()] = node;
                queue.push(neighbor);
            }
        }
    }

    return result;
}