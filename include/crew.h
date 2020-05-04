//Class defining an YPP crew
//It contains some info related to its webpage and more importantly
//Stores the list of pirates (and web URLs)

#ifndef crew_h
#define crew_h
#include <string>
#include <vector>
#include "pirate.h"
#include "bizdb.h"

class crew
{
    public:
        crew(); //Default constructor
        crew(std::string URL); //Constructor providing the URL to be loaded
        ~crew(){} //Default desctructor

        //Methods
        void Load(std::string URL); //Load the crew provided by the URL
        void AddToDB(bizdb &db); //Loop over crews and add to DB
        std::vector<pirate> GetPirateList(){return piratelist;} //Return list of crews
        pirate GetPirate(int index){return piratelist[index];} //Return pirate index index
        pirate GetPirate(std::string piratename); //Return pirate with name piratename
        std::string GetURL(){return URL;} //Return crew URL
        std::string GetName(){return crewname;} //Return crew name
    private:
        //Variables
        std::vector<pirate> piratelist; //List of pirates in flag
        std::string URL; //URL of the crew
        std::string crewname; //Name of the crew
        bool isLoaded; //Flag to check whether this has been loaded from URL already

        //Methods
        void AddShoppesToDB(bizdb &db); //Loop over pirates and add shoppes to DB
        void AddStallsToDB(bizdb &db); //Loop over pirates and add stalls to DB
};

#endif
