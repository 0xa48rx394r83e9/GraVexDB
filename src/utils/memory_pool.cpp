#include "memory_pool.h"
#include <cstdlib>
#include <iostream>

MemoryPool::MemoryPool(size_t blockSize, size_t numBlocks) : blockSize(blockSize)
{
    for (size_t i = 0; i < numBlocks; ++i)
    {
        void *block = std::malloc(blockSize);
        if (block == nullptr)
        {
            throw std::bad_alloc();
        }
        freeBlocks.push_back(block);
    }
}

MemoryPool::~MemoryPool()
{
    for (void *block : freeBlocks)
    {
        std::free(block);
    }
    freeBlocks.clear();
}

void *MemoryPool::allocate()
{
    if (freeBlocks.empty())
    {
        void *block = std::malloc(blockSize);
        if (block == nullptr)
        {
            throw std::bad_alloc();
        }
        return block;
    }
    else
    {
        void *block = freeBlocks.back();
        freeBlocks.pop_back();
        return block;
    }
}

void MemoryPool::deallocate(void *ptr)
{
    freeBlocks.push_back(ptr);
}