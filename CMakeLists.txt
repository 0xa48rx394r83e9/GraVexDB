cmake_minimum_required(VERSION 3.10)
project(GraphDatabase)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the compiler flags for M1 Mac using GCC
set(CMAKE_CXX_FLAGS "-march=armv8-a+crypto -mtune=apple-a14 -O3")

# Include directories
include_directories(include)

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Executable target
add_executable(graph_db ${SOURCES})

# Include the 'include' directory in the target's include path
target_include_directories(graph_db PRIVATE include)

# Benchmark targets
add_executable(graph_benchmark benchmarks/graph_benchmark.cpp)
target_link_libraries(graph_benchmark graph_db)

add_executable(traversal_benchmark benchmarks/traversal_benchmark.cpp)
target_link_libraries(traversal_benchmark graph_db)

# Test targets
enable_testing()

add_executable(graph_test tests/graph/graph_test.cpp)
target_link_libraries(graph_test graph_db)
add_test(NAME graph_test COMMAND graph_test)

add_executable(graph_traversal_test tests/graph/graph_traversal_test.cpp)
target_link_libraries(graph_traversal_test graph_db)
add_test(NAME graph_traversal_test COMMAND graph_traversal_test)

add_executable(graph_query_test tests/graph/graph_query_test.cpp)
target_link_libraries(graph_query_test graph_db)
add_test(NAME graph_query_test COMMAND graph_query_test)

add_executable(graph_serializer_test tests/graph/graph_serializer_test.cpp)
target_link_libraries(graph_serializer_test graph_db)
add_test(NAME graph_serializer_test COMMAND graph_serializer_test)