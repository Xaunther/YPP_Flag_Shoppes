//Implementation file for flag class

#include <string>
#include "crew.h"
#include "pirate.h"
#include "bizdb.h"

crew::crew():
    URL(""),
    crewname(""),
    isLoaded(false)
    {}

crew::crew(std::string URL)
{
    crew::Load(URL);
}

void crew::Load(std::string URL)
{
    return;
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