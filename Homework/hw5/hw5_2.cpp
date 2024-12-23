#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
std::string strip(const std::string &str)
{
    std::string str1 = str;
    std::string::iterator begin = str1.begin();
    std::string::iterator end = str1.end();
    std::string::iterator a = str1.begin();
    while(begin != end && std::isspace(*begin))
    {
        begin++;
    }
    while(begin != end && std::isspace(*(end-1)))
    {
        end--;
    }
    return str1.substr(begin-a, end-begin);
};

std::string join(const std::string &sep, const std::vector<std::string> &strings)
{
    std::string str1;
    if (strings.empty() == true)
    {
        str1 = "";
    }
    else if (strings.empty() == false)
    {
        int len = strings.size();
        str1 = strings[0];
        for (int i=0; i<(len-1); i++)
        {
            str1.append(sep+strings[i+1]);
        }
    }
    return str1;
};

std::vector<std::string> split(const std::string &str, const std::string &sep)
{
    std::string str1 = str;
    std::vector<std::string> res{};
    size_t end;
    while (str1.find(sep) != std::string::npos)
    {
        end = str1.find(sep, 0);
        res.push_back(str1.substr(0, end));
        str1.erase(0, end+sep.size());
    }
    res.push_back(str1);
    return res;
};

std::string swapcase(std::string str)
{
    int len = str.size();
    std::string str1 = str;
    for (int i=0; i<len; i++)
    {
        if (std::islower(str[i]))
        {
            str1[i] = std::toupper(str[i]);
        }
        else if (std::isupper(str[i]))
        {
            str1[i] = std::tolower(str[i]);
        }
    }
    return str1;
}
