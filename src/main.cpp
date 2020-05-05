//testing

//C++ headers
#include <string>
#include <iostream>
#include <vector>
//Project files
#include "flag.h"
#include "bizdb.h"

//USAGE:
//All arguments are interpreted as flag URLs, except the last one.
//The last one must provide the filename where to save the database
//EXAMPLE:
//YPP_Flag_Shoppes.exe "http://emerald.puzzlepirates.com/yoweb/flag/info.wm?flagid=10006353&classic=true" IC_database.txt
int main(int argc, char *argv[])
{
    bizdb mydb;
    std::vector<flag> flaglist;
    for (int i = 1; i < argc - 1; i++)
    {
        flaglist.push_back(flag(argv[i]));
    }

    for (unsigned int i = 0; i < flaglist.size(); i++)
    {
        flaglist[i].Load();
        mydb.RegisterBiz(flaglist[i]);
    }

    mydb.Print();
    mydb.PrintToFile(argv[argc - 1]);
    return 0;
}