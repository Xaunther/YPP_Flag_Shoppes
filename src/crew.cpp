//Implementation file for flag class

#include <string>
#include <iostream>
#include <fstream>
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
    //This function looks for the crew name and returns it
    //The search ends when this line is found
    std::string trigger_line = "<td bgcolor=\"#CDCEB5\" width=\"246\" height=\"213\" align=\"center\">";
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
            //The name of the crew is like <b>flag name</b> in the following line
            std::getline(infile, _line);
            return _line.substr(_line.find("<b>") + 3, _line.find("</b>") - _line.find("<b>") - 3);
        }
    }
    return "";
}

//Read Pirate List
std::vector<pirate> crew::LoadPirateList()
{
    //For this we go searching, and in each result we fill up a vector of crews, which is recursively loaded
    std::vector<pirate> _piratelist;
    std::string trigger_line = "/yoweb/pirate.wm?";
    std::string abort_line = "/yoweb/images/crew-jobbing.png";
    std::string _line;
    //Open file and make sure it exists
    std::ifstream infile;
    infile.open(this->filename.c_str());
    if (!infile)
        return _piratelist;
    //Loop until we find the trigger line
    //Watch out! We on't wanna count jobbers in. So if we reach the jobbing pirate section we stop searching
    while (!infile.eof())
    {
        std::getline(infile, _line);
        if (_line.find(abort_line) != std::string::npos) //ABORT! We reached the jobbing pirates
        {
            return _piratelist;
        }

        if (_line.find(trigger_line) != std::string::npos) //FOUND!
        {
            //The name of the crew is in this same line
            //Cut out the first part
            _line = _line.substr(_line.find("/yoweb/"));
            std::string _URL = _line.substr(0, _line.find("\">"));
            _piratelist.push_back(pirate("http://" + this->GetOcean() + ".puzzlepirates.com" + _URL));
            _piratelist[_piratelist.size() - 1].Load();
        }
    }
    return _piratelist;
}

pirate crew::GetPirate(std::string piratename)
{
    for (unsigned int i = 0; i < this->piratelist.size(); i++)
    {
        if (piratename == piratelist[i].GetName())
        {
            return piratelist[i];
        }
    }
    return pirate();
}
