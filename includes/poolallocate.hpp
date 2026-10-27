#pragma once 
#include<vector>
#include <cstddef>
#include<memory>
#include<new>
#include<stdexcept>


template<typename T, size_t Block_size = 10> 
class poolallocate
{
private:
struct Pool
{
    struct freenode
    {
        freenode* next;
    };
    freenode* free = nullptr;
    std::vector<void*> allocatebBlock;
    Pool() = default;
    ~Pool(){
        for (void* block: allocatebBlock)
        {
            ::operator delete(block);
        }
        
    }

    void *allocate(size_t n)
    {
        if (n != 1)
        {
            void* p = ::operator new(n * sizeof(T));
            allocatebBlock.push_back(p);
            return p;
        }

        if (free == nullptr)
        {
            size_t  allocateSize = Block_size * sizeof(T);
            void* new_block= ::operator new(allocateSize);
            allocatebBlock.push_back(new_block);

            char* ptr = static_cast<char*>(new_block);
            for (size_t i = 0; i <Block_size; ++i)
            {
                freenode* node = reinterpret_cast<freenode*>(ptr + i * sizeof(T));
                node-> next = free;
                free = node;

            }
            
        }
        freenode* node = free;
        free = free -> next;
        return node;
    }

    void dellalocate(void* p, size_t n){
        if (n != 1)
        {
            ::operator delete(p);
            return;
        }
        freenode* node = static_cast<freenode*>(p);
        node->next = free;
        free = node;
    }


};  
std::shared_ptr<Pool> pool_;


public:
    using value_type = T;
    template<typename T>
    struct rebind
    {
        using other = poolallocate<U,Block_size>;   
    };


    poolallocate(const poolallocate<U, Block_size>& other) noexcept : pool_(other.pool_){}

    T *allocate(std::size_t n)
    {
        return static_cast<T *>(pool_->allocate(n));
    }

    void deallocate(T *p, std::size_t n)
    {
        pool_->deallocate(p, n);
    }

  
    template <typename U>
    bool operator==(const PoolAllocator<U, BlockSize> &other) const noexcept
    {
        return pool_ == other.pool_;
    }

    template <typename U>
    bool operator!=(const PoolAllocator<U, BlockSize> &other) const noexcept
    {
        return !(*this == other);
    }
};


