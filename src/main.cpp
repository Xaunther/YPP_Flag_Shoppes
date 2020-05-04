//testing

//C++ headers
#include <string>
#include <iostream>
//Project files
#include "flag.h"
#include "pirate.h"
#include "crew.h"
#include "biz.h"

int main(int argc, char *argv[])
{
    pirate mypirate("http://emerald.puzzlepirates.com/yoweb/pirate.wm?classic=true&target=Monlizzy");
    crew mycrew("http://emerald.puzzlepirates.com/yoweb/crew/info.wm?crewid=5033758&classic=true");
    flag myflag("http://emerald.puzzlepirates.com/yoweb/flag/info.wm?flagid=10006353&classic=true");
    return 0;
}