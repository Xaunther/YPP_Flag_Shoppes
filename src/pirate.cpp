//Implementation file for pirate class

#include <string>
#include "pirate.h"
#include "ypp_page.h"
#include "biz.h"
#include "bizdb.h"

pirate::pirate() : URL(""),
                   piratename(""),
                   isLoaded(false)
{
}

//If providing URL, download it
pirate::pirate(std::string _URL) : ypp_page(_URL),
                                   isLoaded(false)
{
}

void pirate::Load()
{
    //Load crewname
    this->piratename = pirate::LoadPirateName();
    //Load vector of crews with their URLs, loads recursively
    this->bizlist = pirate::LoadBizList();

    //Set loaded flag to true
    this->isLoaded = true;
    return;
}

//Read Pirate Name
std::string pirate::LoadPirateName()
{
    return "";
}

//Read biz List
std::vector<biz> pirate::LoadBizList()
{
    std::vector<biz> testbiz;
    return testbiz;
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
