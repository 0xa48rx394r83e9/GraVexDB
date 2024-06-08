#pragma once

#include <memory>
#include <vector>
#include <cstddef>

class MemoryPool
{
public:
    MemoryPool(size_t blockSize, size_t numBlocks);
    ~MemoryPool();

    void *allocate();
    void deallocate(void *ptr);

private:
    size_t blockSize;
    std::vector<void *> freeBlocks;
};

template <typename T>
class PoolAllocator
{
public:
    using value_type = T;

    PoolAllocator(MemoryPool &pool) : pool(pool) {}

    T *allocate(size_t n)
    {
        if (n != 1)
            throw std::bad_alloc();
        return static_cast<T *>(pool.allocate());
    }

    void deallocate(T *ptr, size_t n)
    {
        if (n != 1)
            throw std::invalid_argument("PoolAllocator can only deallocate one object at a time");
        pool.deallocate(ptr);
    }

private:
    MemoryPool &pool;
};