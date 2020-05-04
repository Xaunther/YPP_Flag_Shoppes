//Class defining an YPP pirate
//It contains some info related to its webpage and more importantly
//Stores its list of shoppes and stalls

#ifndef pirate_h
#define pirate_h
#include <string>
#include <vector>
#include "ypp_page.h"
#include "biz.h"
#include "bizdb.h"

class pirate : public ypp_page
{
public:
    pirate(); //Default constructor
    pirate(std::string _URL);

    //Methods
    void Load();                                             //Load the pirate provided by the URL
    void AddToDB(bizdb &db);                                 //Loop over stalls and shoppes and add to DB
    std::vector<biz> GetBizList() { return bizlist; }        //Return list of businesses
    biz GetBiz(int index) { return bizlist[index]; }         //Return biz index index
    std::vector<biz> GetBiz(std::string bizname);            //Return businesses matching a name
    biz GetBiz(std::string bizname, std::string islandname); //Return business matching name and island (only 1!)
    std::string GetURL() { return URL; }                     //Return pirate URL
    std::string GetName() { return piratename; }             //Return pirate name
private:
    //Variables
    std::vector<biz> bizlist; //List of pirates in flag
    std::string URL;          //URL of the crew
    std::string piratename;   //Name of the crew
    bool isLoaded;            //Flag to check whether this has been loaded from URL already

    //Methods
    std::string LoadPirateName();
    std::vector<biz> LoadBizList();
    void AddShoppesToDB(bizdb &db); //Loop over biz and add shoppes to DB
    void AddStallsToDB(bizdb &db);  //Loop over biz and add stalls to DB
};

#endif
