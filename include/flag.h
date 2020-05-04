//Class defining an YPP flag
//It contains some info related to its webpage and more importantly
//Stores the list of crews (and web URLs)

#ifndef flag_h
#define flag_h
#include <string>
#include <vector>
#include "crew.h"
#include "bizdb.h"

class flag
{
    public:
        flag(); //Default constructor
        flag(std::string URL); //Constructor providing the URL to be loaded
        ~flag(){} //Default desctructor

        //Methods
        void Load(std::string URL); //Load the flag provided by the URL
        void AddToDB(bizdb &db); //Loop over crews and add to DB
        std::vector<crew> GetCrewList(){return crewlist;} //Return list of crews
        crew GetCrew(int index){return crewlist[index];} //Return crew index i
        crew GetCrew(std::string crewname); //Return crew with name crewname
        std::string GetURL(){return URL;} //Return flag URL
        std::string GetName(){return flagname;} //Return flag name
    private:
        //Variables
        std::vector<crew> crewlist; //List of crews in flag
        std::string URL; //URL of the flag
        std::string flagname; //Name of the flag
        bool isLoaded; //Flag to check whether this has been loaded from URL already

        //Methods
        void AddShoppesToDB(bizdb &db); //Loop over crews and add shoppes to DB
        void AddStallsToDB(bizdb &db); //Loop over crews and add stalls to DB
};
#endif
