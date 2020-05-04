//Implementation file for flag class

//C++ headers
#include <string>
#include <iostream>
//External libraries
#include <curl/curl.h>
//Project files
#include "flag.h"
#include "ypp_page.h"
#include "crew.h"
#include "bizdb.h"
#include "Write_Data.h"
#include "DownloadURL.h"

//Initialize empty strings with default constructor
flag::flag() : URL("caca"),
               flagname(""),
               isLoaded(false)
{
}

//If providing URL, download it
flag::flag(std::string _URL) : isLoaded(false),
                               ypp_page(_URL)
{
}

//Load webpage and extract required info
void flag::Load()
{
    //Load flagname
    this->flagname = flag::LoadFlagName();
    //Load vector of crews with their URLs, loads recursively
    this->crewlist = flag::LoadCrewList();

    //Set loaded flag to true
    this->isLoaded = true;
    return;
}

//Read Flag Name
std::string flag::LoadFlagName()
{
    return "";
}

//Read Crew List
std::vector<crew> flag::LoadCrewList()
{
    std::vector<crew> testcrew;
    return testcrew;
}

void flag::AddToDB(bizdb &db)
{
    flag::AddShoppesToDB(db);
    flag::AddStallsToDB(db);
    return;
}

crew flag::GetCrew(std::string crewname)
{
    crew testcrew;
    return testcrew;
}

void flag::AddShoppesToDB(bizdb &db)
{
    return;
}
void flag::AddStallsToDB(bizdb &db)
{
    return;
}