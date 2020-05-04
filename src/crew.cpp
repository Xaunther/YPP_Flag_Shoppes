//Implementation file for flag class

#include <string>
#include "ypp_page.h"
#include "crew.h"
#include "pirate.h"
#include "bizdb.h"

crew::crew() : URL(""),
               crewname(""),
               isLoaded(false)
{
}

//If providing URL, download it
crew::crew(std::string _URL) : ypp_page(_URL),
                               isLoaded(false)
{
}

void crew::Load()
{
    //Load crewname
    this->crewname = crew::LoadCrewName();
    //Load vector of crews with their URLs, loads recursively
    this->piratelist = crew::LoadPirateList();

    //Set loaded flag to true
    this->isLoaded = true;
    return;
}

//Read Crew Name
std::string crew::LoadCrewName()
{
    return "";
}

//Read Pirate List
std::vector<pirate> crew::LoadPirateList()
{
    std::vector<pirate> testpirate;
    return testpirate;
}

void crew::AddToDB(bizdb &db)
{
    crew::AddShoppesToDB(db);
    crew::AddStallsToDB(db);
    return;
}

pirate crew::GetPirate(std::string piratename)
{
    pirate testpirate;
    return testpirate;
}

void crew::AddShoppesToDB(bizdb &db)
{
    return;
}
void crew::AddStallsToDB(bizdb &db)
{
    return;
}