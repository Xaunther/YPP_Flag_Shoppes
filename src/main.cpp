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
void PrintUsage()
{
    std::cout << "Welcome to YPP_Flag_Shoppes. You attempted to use the script without any arguments, which will do nothing." << std::endl;
    std::cout << "Correct usage of the script is as follows:" << std::endl;
    std::cout << "Open a terminal and navigate to the executable folder. Once inside you can use the script." << std::endl;
    std::cout << "YPP_Flag_Shoppes.exe \"<flagURL1>\" \"<flagURL2>\" \"<flagURL3>\"... <outputfile>" << std::endl;
    std::cout << "For example: " << std::endl;
    std::cout << "YPP_Flag_Shoppes.exe \"http://emerald.puzzlepirates.com/yoweb/flag/info.wm?flagid=10006353&classic=true\" IC_database.html" << std::endl;
    std::cout << "WOOP WOOP!" << std::endl;
}
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        PrintUsage();
        return 0;
    }

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
    mydb.PrintXML(argv[argc - 1]);
    return 0;
}