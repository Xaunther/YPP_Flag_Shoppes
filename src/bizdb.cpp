//Implementation file for bizdb class

//Project files
#include "bizdb.h"
#include "biz.h"
#include "pirate.h"
#include "crew.h"
#include "flag.h"
#include <ostream>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

void bizdb::RegisterBiz(flag _flag)
{
    for (unsigned int i = 0; i < _flag.GetCrewList().size(); i++)
        bizdb::RegisterBiz(_flag.GetCrewList()[i]);
}
void bizdb::RegisterBiz(crew _crew)
{
    for (unsigned int i = 0; i < _crew.GetPirateList().size(); i++)
        bizdb::RegisterBiz(_crew.GetPirateList()[i]);
}
void bizdb::RegisterBiz(pirate _pirate)
{
    for (unsigned int i = 0; i < _pirate.GetBizList().size(); i++)
        bizdb::RegisterBiz(_pirate.GetBizList()[i]);
}
void bizdb::RegisterBiz(biz _biz)
{
    //We only register new businesses. If it exists, we update the manager/owner info
    for (unsigned int i = 0; i < this->bizlist.size(); i++)
    {
        //If it exists, update
        if (_biz.GetBizName() == this->bizlist[i].GetBizName() && _biz.GetIslandName() == this->bizlist[i].GetIslandName())
        {
            this->bizlist[i].Update(_biz);
            return;
        }
    }
    //If no matching biz was found, add new!
    this->bizlist.push_back(_biz);
}
void bizdb::Print()
{
    bizdb::Print(std::cout);
}
void bizdb::PrintToFile(std::string filename)
{
    std::ofstream outf;
    outf.open(filename.c_str());
    if (!outf)
        return;
    bizdb::Print(outf);
    outf.close();
}

void bizdb::Print(std::ostream &stream)
{
    //Print each biz
    for (unsigned int i = 0; i < this->bizlist.size(); i++)
    {
        stream << std::setw(34) << this->bizlist[i].GetBizName() << " | ";
        stream << std::setw(32) << this->bizlist[i].GetIslandName() << " | ";
        stream << std::setw(13) << this->bizlist[i].GetBizTypeString() << " | ";
        stream << std::setw(16) << this->bizlist[i].GetOwnerName() << " | ";
        for (unsigned j = 0; j < this->bizlist[i].GetManagerName().size(); j++)
        {
            stream << this->bizlist[i].GetManagerName()[j];
            if (j < this->bizlist[i].GetManagerName().size() - 1)
                stream << ", ";
        }
        stream << std::endl;
    }
}