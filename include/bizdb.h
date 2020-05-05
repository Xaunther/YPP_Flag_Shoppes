//Database to store all found businesses

#ifndef bizdb_h
#define bizdb_h

#include <vector>
#include <ostream>
#include <string>
#include "biz.h"
#include "pirate.h"
#include "crew.h"
#include "flag.h"

class bizdb
{
public:
    bizdb() {}                              //Default constructor
    ~bizdb() {}                             //Default destructor
    void RegisterBiz(flag _flag);           //Add all biz from flag to DB
    void RegisterBiz(crew _crew);           //Add all biz from crew to DB
    void RegisterBiz(pirate _pirate);       //Add all biz from pirate to DB
    void RegisterBiz(biz _biz);             //Register new biz
    void Print();                           //Print to screen
    void PrintToFile(std::string filename); //Print to file

private:
    std::vector<biz> bizlist; //List containing all businesses

    //Methods
    void Print(std::ostream &stream); //Method to handle the print into desired stream
};

#endif