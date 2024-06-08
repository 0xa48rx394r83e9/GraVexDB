#include "graph.h"
#include "graph_traversal.h"
#include "graph_query.h"
#include <chrono>
#include <iostream>

void benchmarkGraphOperations(std::shared_ptr<Graph> graph)
{
    // Benchmark adding nodes
    auto startTime = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000; ++i)
    {
        graph->addNode(i);
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    std::cout << "Adding nodes: " << duration << " microseconds" << std::endl;

    // Benchmark adding edges
    startTime = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 9999; ++i)
    {
        graph->addEdge(i, i + 1, 1);
    }
    endTime = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    std::cout << "Adding edges: " << duration << " microseconds" << std::endl;

    // Benchmark BFS traversal
    startTime = std::chrono::high_resolution_clock::now();
    GraphTraversal::BFS(graph, 0);
    endTime = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    std::cout << "BFS traversal: " << duration << " microseconds" << std::endl;

    // Benchmark shortest path query
    startTime = std::chrono::high_resolution_clock::now();
    GraphQuery::getShortestPath(graph, 0, 9999);
    endTime = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    std::cout << "Shortest path query: " << duration << " microseconds" << std::endl;
}

int main()
{
    auto graph = std::make_shared<Graph>();
    benchmarkGraphOperations(graph);
    return 0;
}