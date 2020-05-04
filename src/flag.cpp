//Implementation file for flag class

//C++ headers
#include <string>
#include <iostream>
//External libraries
#include <curl/curl.h>
//Project files
#include "flag.h"
#include "crew.h"
#include "bizdb.h"
#include "Write_Data.h"
#include "DownloadURL.h"

//Initialize empty strings with default constructor
flag::flag() : URL(""),
               flagname(""),
               isLoaded(false)
{
}

//If providing URL, Load it
flag::flag(std::string URL)
{
    flag::Load(URL);
}

void flag::Load(std::string URL)
{
    //Download URL into a file
    DownloadURL(URL);
    return;
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