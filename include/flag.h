//Class defining an YPP flag
//It contains some info related to its webpage and more importantly
//Stores the list of crews (and web URLs)

#ifndef flag_h
#define flag_h
#include <string>
#include <vector>
#include "ypp_page.h"
#include "crew.h"
#include "bizdb.h"

class flag : public ypp_page
{
public:
    flag(); //Default constructor
    flag(std::string _URL);

    //Methods
    void Load();                                         //Load the flag provided by the URL
    void AddToDB(bizdb &db);                             //Loop over crews and add to DB
    std::vector<crew> GetCrewList() { return crewlist; } //Return list of crews
    crew GetCrew(int index) { return crewlist[index]; }  //Return crew index i
    crew GetCrew(std::string crewname);                  //Return crew with name crewname
    std::string GetURL() { return URL; }                 //Return flag URL
    std::string GetName() { return flagname; }           //Return flag name
private:
    //Variables
    std::vector<crew> crewlist; //List of crews in flag
    std::string URL;            //URL of the flag
    std::string flagname;       //Name of the flag
    bool isLoaded;              //Flag to check whether this has been loaded from URL already

    //Methods
    std::string LoadFlagName();
    std::vector<crew> LoadCrewList();
    void AddShoppesToDB(bizdb &db); //Loop over crews and add shoppes to DB
    void AddStallsToDB(bizdb &db);  //Loop over crews and add stalls to DB
};
#endif
