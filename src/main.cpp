//testing

//C++ headers
#include <string>
#include <iostream>
//Project files
#include "flag.h"
#include "pirate.h"
#include "crew.h"
#include "biz.h"
#include "bizdb.h"

int main(int argc, char *argv[])
{
    bizdb mydb;
    flag myflag("http://emerald.puzzlepirates.com/yoweb/flag/info.wm?flagid=10006353&classic=true");
    myflag.Load();
    mydb.RegisterBiz(myflag);
    mydb.Print();
    mydb.PrintToFile("IC_database");


    return 0;
}