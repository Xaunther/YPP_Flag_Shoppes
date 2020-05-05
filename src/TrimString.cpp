//Implementation of TrimString function
#include <string>
#include "TrimString.h"

std::string TrimString(std::string _str)
{
    return _str.substr(_str.find_first_not_of(" "), _str.find_last_not_of(" ") - _str.find_first_not_of(" ") + 1);
}