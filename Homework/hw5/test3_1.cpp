#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
std::vector<std::string> split(const std::string &str, const std::string &sep)
{
    std::string str1 = str;
    std::string::iterator begin = str1.begin();
    std::string::iterator end = str1.begin();
    std::size_t len = sep.size();
    std::vector<std::string> res{};
    std::size_t pos = 0;
    while (str1.find_first_of(sep,pos) != std::string::npos)
    {
        end = end + str1.find_first_of(sep,pos)-pos;
        res.push_back(std::string(begin, end));
        begin = end + len;
        end = end + len;
        pos = str1.find_first_of(sep,pos)+len;
    }
    res.push_back(std::string(end,str1.end()));
    return res;
};

int main()
{
    split("xaaaxxbbbxcdefg", "x");
    return 0;
}