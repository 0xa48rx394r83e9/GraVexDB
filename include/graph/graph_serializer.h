#pragma once

#include <string>
#include <memory>

class Graph;

class GraphSerializer
{
public:
    static void serialize(std::shared_ptr<Graph> graph, const std::string &filename);
    static std::shared_ptr<Graph> deserialize(const std::string &filename);

private:
    GraphSerializer();
};