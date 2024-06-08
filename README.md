# ✦༺✧ GraVexDB ✧༻✦

Welcome to my high-performance, in-memory graph database project! This project was developed as a learning experience to gain a deeper understanding of graph databases and optimize their performance using C++. The goal was to create an efficient and fast graph database that can handle large-scale data and complex queries.

## ✧ Features

- **In-Memory Storage**: The graph database is designed to store all data in memory, providing lightning-fast access and eliminating the need for disk I/O operations.
- **High Performance**: Leveraging the power of C++, the database is optimized for speed and efficiency, allowing for quick traversal and querying of large graphs.
- **Flexible Graph Structure**: The database supports a flexible graph structure, allowing nodes and edges to have arbitrary properties and attributes.
- **Efficient Algorithms**: Implements efficient algorithms for common graph operations, such as breadth-first search (BFS), depth-first search (DFS), and shortest path finding.
- **Thread-Safe**: The database is designed to be thread-safe, enabling concurrent access and modifications from multiple threads.
- **Serialization**: Provides functionality to serialize and deserialize the graph data, allowing for persistent storage and retrieval.

## ✧ Getting Started

To get started with the graph database, follow these steps:

1. Clone the repository:

   ```
   git clone https://github.com/your-username/graph-database.git
   ```

2. Navigate to the project directory:

   ```
   cd graph-database
   ```

3. Build the project using CMake:

   ```
   mkdir build
   cd build
   cmake ..
   make
   ```

4. Run the tests to ensure everything is working correctly:

   ```
   ctest
   ```

5. You can now use the graph database in your own projects by linking against the `graph_db` library.

## ✧ Usage

Here's a simple example of how to use the graph database:

```cpp
#include "graph.h"
#include "graph_traversal.h"
#include "graph_query.h"
#include <iostream>

int main() {
    auto graph = std::make_shared<Graph>();

    // Adding nodes
    graph->addNode(1);
    graph->addNode(2);
    graph->addNode(3);

    // Adding edges
    graph->addEdge(1, 2, 1);
    graph->addEdge(1, 3, 1);
    graph->addEdge(2, 3, 1);

    // Performing BFS traversal
    auto bfsResult = GraphTraversal::BFS(graph, 1);
    std::cout << "BFS Traversal: ";
    for (const auto& node : bfsResult) {
        std::cout << node->getId() << " ";
    }
    std::cout << std::endl;

    // Performing shortest path query
    auto shortestPath = GraphQuery::getShortestPath(graph, 1, 3);
    std::cout << "Shortest Path: ";
    for (const auto& node : shortestPath) {
        std::cout << node->getId() << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

## ✧ Benchmarks

The project includes benchmark tests to measure the performance of various graph operations. To run the benchmarks, use the following commands:

```
./graph_benchmark
./traversal_benchmark
```

The benchmark results will be displayed in the console, showing the execution time for each operation.

## ✧ Future Enhancements

Here are some planned enhancements and features for the graph database:

- [ ] Support for persistent storage using disk-based indexes
- [ ] Implement more advanced graph algorithms, such as PageRank and community detection
- [ ] Optimize memory usage and reduce memory fragmentation
- [ ] Enhance query capabilities with support for complex graph patterns and regular expressions
- [ ] Develop a Python binding for easy integration with other projects

## ✧ License

This project is licensed under the [MIT License](LICENSE).
