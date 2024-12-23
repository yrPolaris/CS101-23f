#include <iostream>
#include <string>
#include <vector>
std::string strip(const std::string &str)
{
    std::string str1 = str;
    int begin = 0;
    int len = str.size();
    for (int i=0; i<len; i++)
    {
        if (std::isspace(str1[i]))
        {
            str1.erase(0,1);
            i = -1;
            len--;
        }
        else if (!std::isspace(str1[i]))
        {
            begin = i;
            break;
        }
    }
    for (int i=begin; i<len; i++)
    {
        if (std::isspace(str1[i]))
        {
            str1.erase(i);
            break;
        }
    }
    return str1;
};

int main()
{
    std::string str = strip(" wefafwefw \n");
}
