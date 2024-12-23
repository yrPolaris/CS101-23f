#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP

#include <cstddef>
#include <stdexcept>
#include <iostream>

class Dynarray 
{

    int *ptr;
    std::size_t len;
    int x;


  public:
    static const std::size_t npos = static_cast<std::size_t>(-1);
    using size_type = std::size_t;
    using value_type = int;
    using pointer = int *;
    using reference = int &;
    using const_pointer = const int *;
    using const_reference = const int &;
    
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
    size_type find(int num) const
    {
        if (len == 0)
        {
            return Dynarray::npos;
        }
        size_type res = len+1;
        for (size_type i = 0; i < len; i++)
        {
            if (ptr[i] == num)
            {
                res = i;
                break;
            }
        }
        if (res != len+1)
        {
            return res;
        }
        return Dynarray::npos;
    }

  public:
    size_type find(int num, size_type pos) const
    {
        size_type res = len+1;
        if (pos >= len)
        {
            return Dynarray::npos;
        }
        for (size_type i = pos; i < len; i++)
        {
            if (ptr[i] == num)
            {
                res = i;
                break;
            }
        }
        if (res != len+1)
        {
            return res;
        }
        return Dynarray::npos;
    }
  
  public:
    int& operator[] (std::size_t i)
    {
        return ptr[i];
    }

    const int& operator[] (std::size_t i) const
    {
        return ptr[i];
    }

    friend bool operator<(const Dynarray &lhs, const Dynarray &rhs)
    {
        std::size_t len = 0;
        std::size_t lhs_len = lhs.len;
        std::size_t rhs_len = rhs.len;
        if (lhs_len >= rhs_len)
        {
            len = rhs_len;
        }
        else if (lhs_len < rhs_len)
        {
            len = lhs_len;
        }
        if (len != 0)
        {
            for (std::size_t i = 0; i < len; i++)
            {
                if (lhs.ptr[i] != rhs.ptr[i])
                {
                    return lhs.ptr[i] < rhs.ptr[i];
                }
                else if (i == len - 1 && lhs.ptr[i] == rhs.ptr[i])
                {
                    return lhs_len < rhs_len;
                }            
            }
        }
        return lhs_len < rhs_len;
    }

    friend bool operator==(const Dynarray &lhs, const Dynarray &rhs)
    {
        std::size_t lhs_len = lhs.len;
        std::size_t rhs_len = rhs.len;
        if (lhs_len == rhs_len)
        {
            for (std::size_t i = 0; i < lhs_len; i++)
            {
                if (lhs.ptr[i] != rhs.ptr[i])
                {
                    return lhs.ptr[i] == rhs.ptr[i];
                }
                else if (i == lhs_len - 1 && lhs.ptr[i] == rhs.ptr[i])
                {
                    return lhs_len == rhs_len;
                }
            }
        }
        return lhs_len == rhs_len;
    }

    friend bool operator>(const Dynarray &lhs, const Dynarray &rhs)
    {
        return rhs < lhs;
    }
    friend bool operator<=(const Dynarray &lhs, const Dynarray &rhs)
    {
        return !(lhs > rhs);
    }
    friend bool operator>=(const Dynarray &lhs, const Dynarray &rhs)
    {
        return !(lhs < rhs);
    }
    friend bool operator!=(const Dynarray &lhs, const Dynarray &rhs)
    {
        return !(lhs == rhs);
    }

    friend std::ostream &operator<<(std::ostream &os, const Dynarray &r)
    {
        if (r.len == 0)
        {
            os << "[]";
        }
        else if (r.len != 0)
        {
            os << '[';
            for (std::size_t i = 0; i < r.len-1; i++)
            {
                os << r.ptr[i] << ", ";
            }
            os << r.ptr[r.len-1] << ']';
        }
        return os;
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

    Dynarray(Dynarray &&other) noexcept
    {
        ptr = other.ptr;
        len = other.len;
        other.ptr = nullptr;
        other.len = 0;
    }

    Dynarray &operator=(Dynarray &&other) noexcept 
    {
        if (this != &other)
        {
            delete[] ptr;
            ptr = other.ptr;
            len = other.len;
            other.ptr = nullptr;
            other.len = 0;
        }
        return *this;
    }

    ~Dynarray()
    {
        delete[] ptr;
    }
};

#endif // DYNARRAY_HPP