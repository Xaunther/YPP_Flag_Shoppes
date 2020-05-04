//Implementation file for flag class

#include <string>
#include "flag.h"
#include "crew.h"
#include "bizdb.h"

//Initialize empty strings with default constructor
flag::flag():
    URL(""),
    flagname(""),
    isLoaded(false)
    {}

//If providing URL, Load it
flag::flag(std::string URL)
{
    flag::Load(URL);
}

void flag::Load(std::string URL)
{
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
    
}

void flag::AddShoppesToDB(bizdb &db)
{
    return;
}
void flag::AddStallsToDB(bizdb &db)
{
    return;
}