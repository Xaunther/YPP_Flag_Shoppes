//Implementation file for pirate class

#include <string>
#include "pirate.h"
#include "biz.h"
#include "bizdb.h"

pirate::pirate():
    URL(""),
    piratename(""),
    isLoaded(false)
    {}

pirate::pirate(std::string URL)
{
    pirate::Load(URL);
}

void pirate::Load(std::string URL)
{
    return;
}

void pirate::AddToDB(bizdb &db)
{
    pirate::AddShoppesToDB(db);
    pirate::AddStallsToDB(db);
    return;
}

std::vector<biz> pirate::GetBiz(std::string bizname)
{
    std::vector<biz> testbiz;
    return testbiz;
}

biz pirate::GetBiz(std::string bizname, std::string islandname)
{
    biz testbiz;
    return testbiz;
}

void pirate::AddShoppesToDB(bizdb &db)
{
    return;
}
void pirate::AddStallsToDB(bizdb &db)
{
    return;
}
