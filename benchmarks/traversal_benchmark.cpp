#include "graph.h"
#include "graph_traversal.h"
#include <chrono>
#include <iostream>

void benchmarkTraversalAlgorithms(std::shared_ptr<Graph> graph)
{
    // Benchmark BFS traversal
    auto startTime = std::chrono::high_resolution_clock::now();
    GraphTraversal::BFS(graph, 0);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    std::cout << "BFS traversal: " << duration << " microseconds" << std::endl;

    // Benchmark DFS traversal
    startTime = std::chrono::high_resolution_clock::now();
    GraphTraversal::DFS(graph, 0);
    endTime = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    std::cout << "DFS traversal: " << duration << " microseconds" << std::endl;
}

int main()
{
    auto graph = std::make_shared<Graph>();
    // Add nodes and edges to the graph
    for (int i = 0; i < 10000; ++i)
    {
        graph->addNode(i);
    }
    for (int i = 0; i < 9999; ++i)
    {
        graph->addEdge(i, i + 1, 1);
    }
    benchmarkTraversalAlgorithms(graph);
    return 0;
}