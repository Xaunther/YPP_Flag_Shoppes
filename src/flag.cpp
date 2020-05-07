//Implementation file for flag class

//C++ headers
#include <string>
#include <iostream>
#include <fstream>
//External libraries
#include <curl/curl.h>
//Project files
#include "flag.h"
#include "ypp_page.h"
#include "crew.h"
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
    //This function looks for the flag name and returns it
    //The search ends when this line is found
    std::string trigger_line = "<td bgcolor=\"#CDCEB5\" width=\"246\" height=\"213\" align=\"center\"";
    std::string _line;
    //Open file and make sure it exists
    std::ifstream infile;
    infile.open(this->filename.c_str());
    if (!infile)
        return "";
    //Loop until we find the trigger line
    while (!infile.eof())
    {
        std::getline(infile, _line);
        if (_line.find(trigger_line) != std::string::npos) //FOUND!
        {
            //The name of the flag is like <b>flag name</b> in the following line
            std::getline(infile, _line);
            return _line.substr(_line.find("<b>") + 3, _line.find("</b>") - _line.find("<b>") - 3);
        }
    }
    return "";
}

//Read Crew List
std::vector<crew> flag::LoadCrewList()
{
    //For this we go searching, and in each result we fill up a vector of crews, which is recursively loaded
    std::vector<crew> _crewlist;
    std::string trigger_line = "/yoweb/crew/info.wm?crewid";
    std::string _line;
    //Open file and make sure it exists
    std::ifstream infile;
    infile.open(this->filename.c_str());
    if (!infile)
        return _crewlist;
    //Loop until we find the trigger line
    while (!infile.eof())
    {
        std::getline(infile, _line);
        if (_line.find(trigger_line) != std::string::npos) //FOUND!
        {
            //The name of the crew is in this same line
            std::string _URL = _line.substr(_line.find("/yoweb/"), _line.find("=true") + 5 - _line.find("/yoweb/"));
            _crewlist.push_back(crew("http://" + this->GetOcean() + ".puzzlepirates.com" + _URL));
            _crewlist[_crewlist.size() - 1].Load();
        }
    }
    return _crewlist;
}

crew flag::GetCrew(std::string crewname)
{
    for (unsigned int i = 0; i < this->crewlist.size(); i++)
    {
        if (crewname == crewlist[i].GetName())
        {
            return crewlist[i];
        }
    }
    return crew();
}
