//Class defining an YPP crew
//It contains some info related to its webpage and more importantly
//Stores the list of pirates (and web URLs)

#ifndef crew_h
#define crew_h
#include <string>
#include <vector>
#include "ypp_page.h"
#include "pirate.h"

class crew : public ypp_page
{
public:
    crew(); //Default constructor
    crew(std::string _URL);

    //Methods
    void Load();                                               //Load the crew provided by the URL
    std::vector<pirate> GetPirateList() { return piratelist; } //Return list of crews
    pirate GetPirate(int index) { return piratelist[index]; }  //Return pirate index index
    pirate GetPirate(std::string piratename);                  //Return pirate with name piratename
    std::string GetURL() { return URL; }                       //Return crew URL
    std::string GetName() { return crewname; }                 //Return crew name

private:
    //Variables
    std::vector<pirate> piratelist; //List of pirates in flag
    std::string URL;                //URL of the crew
    std::string crewname;           //Name of the crew
    bool isLoaded;                  //Flag to check whether this has been loaded from URL already

    //Methods
    std::string LoadCrewName();
    std::vector<pirate> LoadPirateList();
};

#endif
