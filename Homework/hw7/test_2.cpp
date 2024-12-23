#include <iostream>
#include "hw7_2.hpp"

int main()
{
    int arr[] = {1, 2, 3, 5};
    Dynarray a(arr, arr + 4);
    Dynarray b;
    std::cout << a << '\n' << b << std::endl;
    return 0;
}







