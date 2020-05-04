//Implementation file for ypp_page class

//C++ headers
#include <string>
#include <iostream>
//Project files
#include "ypp_page.h"
#include "Write_Data.h"
#include "DownloadURL.h"

//Initialize empty strings with default constructor
ypp_page::ypp_page(void) : URL(""),
                       filename("")
{
}

//If providing URL, download it
ypp_page::ypp_page(std::string _URL) : URL(_URL)
{
    ypp_page::Download();
}

void ypp_page::Download()
{
    //Download URL into a file
    this->filename = DownloadURL(this->URL);
    return;
}
