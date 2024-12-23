#include <algorithm>
#include <iostream>

#include <cstddef>
#include <stdexcept>

class Dynarray 
{
    int *ptr;
    std::size_t len;
    const char* begin;
    const char* end;
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
        return ptr[i];
    }
    const int &at(std::size_t i) const
    {
        return ptr[i];
    }
  public:
    Dynarray()
    {
        ptr = new int[0]{};
    };

    explicit Dynarray(std::size_t n)
        :ptr(new int[n]{}), len(n){}


    Dynarray(std::size_t n, int x)
    {
        ptr = new int[n]{x};
        len = n;
    };

    Dynarray(const int* begin, const int* end)
    {
        len = (size_t)(end - begin);
        int num = (int)(end - begin);
        ptr = new int[len]{0};
        for (int i = 0; i < num; i++)
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
        ptr = new int[other.size()];
        for (std::size_t i = 0; i != other.size(); ++i)
        ptr[i] = other.at(i);
        len = other.size();
        return *this;
    }

    ~Dynarray()
    {
        delete[] ptr;
    }
};
void reverse(Dynarray &a) 
{
for (int i = 0, j = a.size() - 1; i < j; ++i, --j)
    {std::swap(a.at(i), a.at(j));}
}
void print(const Dynarray &a) {
std::cout << '[';
if (!a.empty()) 
{
    for (std::size_t i = 0; i + 1 < a.size(); ++i)
        std::cout << a.at(i) << ", ";
    std::cout << a.at(a.size() - 1);
}
std::cout << ']' << std::endl;
}
int main() {
int n;
int ar[5] = {0};
std::cin >> n;
Dynarray aa(n);
Dynarray arr = aa;
for (int i = 0; i != n; ++i)
{
    std::cin >> arr.at(i);
    ar[i] = arr.at(i);
}
reverse(arr);
for (int i = 0; i != n; ++i)
{
    ar[i] = arr.at(i);
}
int abbb = arr.empty();
print(arr);
Dynarray copy = arr;
copy.at(0) = 42;
std::cout << arr.at(0) << '\n'
<< copy.at(0) << std::endl;
return 0;
}