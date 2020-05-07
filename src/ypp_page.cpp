//Implementation file for ypp_page class

//C++ headers
#include <string>
#include <iostream>
//Project files
#include "ypp_page.h"
#include "Write_Data.h"
#include "DownloadURL.h"

//Initialize empty strings with default constructor
ypp_page::ypp_page() : URL(""),
                       filename("")
{
}

//If providing URL, download it
ypp_page::ypp_page(std::string _URL) : URL(_URL)
{
    ypp_page::Download();
}

//Download ocean by looking at the URL
std::string ypp_page::GetOcean()
{
    if (this->URL == "")
        return "";
    size_t first_index = this->URL.find("://") + 3;
    size_t last_index = this->URL.find(".puzzlepirates.com");
    if(first_index == std::string::npos || last_index == std::string::npos)
        return "";
    return this->URL.substr(first_index, last_index-first_index);
}

void ypp_page::Download()
{
    //Download URL into a file
    this->filename = DownloadURL(this->URL);
    std::cout << this->URL << " downloaded at " << this->filename << std::endl;
    return;
}
