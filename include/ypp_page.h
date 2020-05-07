//Parent class defining common things among crew, pirate and flag

#ifndef ypp_page_h
#define ypp_page_h
#include <string>

class ypp_page
{
public:
    ypp_page();                 //Default constructor
    ypp_page(std::string _URL); //Constructor providing the URL to be loaded
    ~ypp_page() {}              //Default desctructor

    //Methods
    std::string GetURL() { return URL; }           //Return flag URL
    std::string GetFilename() { return filename; } //Return flag name
    std::string GetOcean();                        //Returns ocean
protected:
    //Variables
    std::string URL;      //URL of the flag
    std::string filename; //Location of the local html

    //Methods
    void Download(); //Load the page provided by the URL. Also sets filename
};

#endif