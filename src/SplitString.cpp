//Implementation of SplitString
#include <vector>
#include <string>
#include "SplitString.h"

std::vector<std::string> SplitString(std::string s, std::string delimiter)
{
    //Empty string has no elements, DUH
    std::vector<std::string> splitstring;
    if (s == "")
        return splitstring;
    int pos = 0;
    int N = CountString(s, delimiter) + 1;
    for (int i = 0; i < N; i++)
    {
        splitstring.push_back(s.substr(pos, s.find(delimiter, pos) - pos));
        if (i < N - 1)
        {
            pos = int(s.find(delimiter, pos) + delimiter.size());
        }
    }
    return splitstring;
}

int CountString(std::string s, std::string pattern)
{
    int N = 0;
    int pos = 0;
    while (s.find(pattern, pos) != std::string::npos)
    {
        N++;
        pos = int(s.find(pattern, pos) + pattern.size());
    }
    return N;
}
