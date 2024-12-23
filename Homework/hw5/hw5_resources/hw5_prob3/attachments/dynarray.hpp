#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP 1

#include <cstddef>
#include <stdexcept>

class Dynarray 
{
    int *ptr;
    std::size_t len;
    int x;
  public:
    std::size_t size() const
    {
        return len;
    }
    bool empty() const 
    {
        return len == 0;
    }

  public:
    int &at(std::size_t i)
    {
        if (i < len)
        {
            return ptr[i];
        }
        else
        {
            throw std::out_of_range{"Dynarray index out of range!"};
        }

    }
    const int &at(std::size_t i) const
    {
        if (i < len)
        {
            return ptr[i];
        }
        else
        {
            throw std::out_of_range{"Dynarray index out of range!"};
        }
    }
  public:
    Dynarray()
    {
        ptr = nullptr;
        len = 0;
    };

    explicit Dynarray(std::size_t n)
        :ptr(new int[n]{}), len(n){}


    Dynarray(std::size_t n, int x)
    {
        ptr = new int[n];
        len = n;
        for (std::size_t i = 0; i < len; i++)
        {
            ptr[i] = x;
        }
    };

    Dynarray(const int* begin, const int* end)
    {
        len = end - begin;
        ptr = new int[len];
        for (std::size_t i = 0; i < len; i++)
        {
            ptr[i] = *(begin + i);
        }
    };

    Dynarray(const Dynarray &other)
        : ptr(new int[other.size()]{}), len(other.size())
    {
    for (std::size_t i = 0; i != other.size(); ++i)
    ptr[i] = other.at(i);
    }

    Dynarray &operator=(const Dynarray &other) 
    {
        int *new_data = new int[other.size()];
        for (std::size_t i = 0; i != other.size(); ++i)
            new_data[i] = other.at(i);
        delete[] ptr;
        ptr = new_data;
        len = other.size();
        return *this;
    }

    ~Dynarray()
    {
        delete[] ptr;
    }
};


#endif // DYNARRAY_HPP