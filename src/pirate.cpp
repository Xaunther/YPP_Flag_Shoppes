//Implementation file for pirate class

#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include "TrimString.h"
#include "SplitString.h"
#include "pirate.h"
#include "ypp_page.h"
#include "biz.h"

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
    //This case is simple, the filename already contains the name
    return this->filename.substr(this->filename.find("pirate_") + 7, this->filename.find(".html") - this->filename.find("pirate_") - 7);
}

//Read biz List
std::vector<biz> pirate::LoadBizList()
{
    //For this we go searching, and in each result we fill up a vector of crews, which is recursively loaded
    std::vector<biz> _bizlist;
    std::string trigger_line = "/yoweb/images/shop-";
    std::string _line;
    bool stalls = false;  //All are shoppes until stalls is reached
    bool managed = false; //If biz is owned or managed
    //Open file and make sure it exists
    std::ifstream infile;
    infile.open(this->filename.c_str());
    if (!infile)
        return _bizlist;
    //Loop until we find the trigger line
    while (!infile.eof())
    {
        std::getline(infile, _line);

        if (_line.find("<b>Stalls</b>") != std::string::npos)
            stalls = true; //Check if we reached the stalls

        if (_line.find(trigger_line) != std::string::npos) //FOUND!
        {
            //Define biz
            biz _biz;
            //In that same line we get the biz type and if it is managed or owned
            if (_line.find("-managed-") != std::string::npos)
            {
                managed = true;
                _biz.SetBizType(_line.substr(_line.find("-managed-") + 9, _line.find(".png") - _line.find("-managed-") - 9));
                _biz.AddManager(this->piratename);
            }
            else
            {
                managed = false;
                _biz.SetBizType(_line.substr(_line.find("shop-") + 5, _line.find(".png") - _line.find("shop-") - 5));
                _biz.SetOwner(this->piratename);
            }
            //Add build type (stall or shoppe)
            if (stalls)
                _biz.SetBuildType(buildtype::Stall);
            else
                _biz.SetBuildType(buildtype::Shoppe);

            //Finally we must set the name and island. This task is delicate and is different for stalls and shoppes
            if (stalls) //Name and island is in next line
            {
                std::getline(infile, _line);
                std::regex searchword("\\bon\\b");
                std::smatch m;
                std::regex_search(_line, m, searchword);

                std::string resname = _line.substr(_line.find("title=\"") + 7, m.position(m.size() - 1) - _line.find("title=\"") - 8);
                _biz.SetBizName(TrimString(resname));

                resname = _line.substr(m.position(m.size() - 1) + 3, _line.find_last_of("\"") - m.position(m.size() - 1) - 3);
                _biz.SetIsland(TrimString(resname));

                _bizlist.push_back(_biz);
            }
            else if (managed) //Managed shoppe
            {
                //So in this case we could have a group of shoppes of the same type, not just one!
                std::getline(infile, _line);
                std::getline(infile, _line);

                while (_line.find("</font></td>") == std::string::npos)
                {
                    //Clean line
                    _line = _line.substr(_line.find("</b>") + 4);
                    _line = _line.substr(0, _line.find("</font></td>"));
                    //Split same line if there are commas
                    std::vector<std::string> split_line = SplitString(_line, ",");
                    //Do for each element
                    for (unsigned int i = 0; i < split_line.size(); i++)
                    {
                        std::regex searchword("\\bon\\b");
                        std::smatch m;
                        std::regex_search(split_line[i], m, searchword);

                        std::string resname = split_line[i].substr(1, m.position(m.size() - 1) - 1);
                        _biz.SetBizName(TrimString(resname));

                        resname = split_line[i].substr(m.position(m.size() - 1) + 3);
                        _biz.SetIsland(TrimString(resname));

                        _bizlist.push_back(_biz);
                    }
                    std::getline(infile, _line);
                }
            }
            else //Owned shoppe
            {
                //So in this case we could have a group of shoppes of the same type, not just one!
                std::getline(infile, _line);
                std::getline(infile, _line);

                while (_line.find("</tr>") == std::string::npos)
                {
                    //Clean line
                    _line = _line.substr(_line.find("</b>") + 4);
                    _line = _line.substr(0, _line.find("</font></td>"));
                    //Split same line if there are commas
                    std::vector<std::string> split_line = SplitString(_line, ",");
                    //Do for each element
                    for (unsigned int i = 0; i < split_line.size(); i++)
                    {
                        std::regex searchword("\\bon\\b");
                        std::smatch m;
                        std::regex_search(split_line[i], m, searchword);

                        std::string resname = split_line[i].substr(1, m.position(m.size() - 1) - 1);
                        _biz.SetBizName(TrimString(resname));

                        resname = split_line[i].substr(m.position(m.size() - 1) + 3);
                        _biz.SetIsland(TrimString(resname));

                        _bizlist.push_back(_biz);
                    }
                    std::getline(infile, _line);
                }
            }
        }
    }
    return _bizlist;
}

std::vector<biz> pirate::GetBiz(std::string bizname)
{
    std::vector<biz> returnlist;
    for (unsigned int i = 0; i < this->bizlist.size(); i++)
    {
        if (bizname == this->bizlist[i].GetBizName())
        {
            returnlist.push_back(this->bizlist[i]);
        }
    }
    return returnlist;
}

biz pirate::GetBiz(std::string bizname, std::string islandname)
{
    for (unsigned int i = 0; i < this->bizlist.size(); i++)
    {
        if (bizname == this->bizlist[i].GetBizName() && islandname == this->bizlist[i].GetIslandName())
        {
            return this->bizlist[i];
        }
    }
    return biz();
}