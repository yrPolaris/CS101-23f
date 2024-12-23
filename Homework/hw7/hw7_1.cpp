#include <iostream>
#include <vector>
#include <string>



class Dynarray {
  friend std::string foo();

 public:
  using size_type = std::size_t;
  static const size_type npos = -1;

  friend int fun(int);
};


int main()
{
    auto x = 42;
    const auto y = x;
    auto z = y;
    auto &r = y;
    auto m = r;
    Dynarray d;
}











