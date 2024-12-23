#include <iostream>
#include <vector>
#include <math.h>

int main()
{
    std::vector<double> a = {1,2,3,4,5,6};
    a.resize(10, 0.0);
    std::vector<double> b(8, 0);
    a = b;
    return 0;
}



















