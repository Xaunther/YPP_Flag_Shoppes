//Business class. Contains information about a shoppe/stall

#ifndef biz_h
#define biz_h

#include <string>
#include <vector>

//Defie tipes of businesses
enum class biztype
{
    None,
    Apothecary,
    Construction,
    Distillery,
    Estate_Agent,
    Fort,
    Furnisher,
    Inn,
    Iron_Monger,
    Market_Hall,
    Palace,
    Shipyard,
    Tailor,
    Weavery
};

enum class buildtype
{
    None,
    Stall,
    Shoppe
};

class biz
{
public:
    biz();                                                                 //Default constructor
    ~biz() {}                                                              //Default destructor
    biztype GetBizType() { return biz_type; }                              //Get biz type
    std::string GetBizTypeString();                                        //Get biz type as string
    buildtype GetBuildType() { return build_type; }                        //Get building type
    std::string GetBizName() { return bizname; }                           //Get biz name
    std::string GetIslandName() { return island; }                         //Get island name
    std::string GetOwnerName() { return owner; }                           //Get owner name
    std::vector<std::string> GetManagerName() { return manager; }          //Get manager names
    void SetBizType(std::string _biz_type);                                //Set biz type through string
    void SetBizType(biztype _biz_type) { biz_type = _biz_type; }           //Set biz type
    void SetBuildType(buildtype _build_type) { build_type = _build_type; } //Set build type
    void SetBizName(std::string _bizname) { bizname = _bizname; }          //Set biz name
    void SetIsland(std::string _island) { island = _island; }              //Set island name
    void SetOwner(std::string _owner) { owner = _owner; }                  //Set owner name
    void AddManager(std::string _manager) { manager.push_back(_manager); } //Add manager name
    void Update(biz _biz);                                                 //Update biz manager/owner info from other biz

private:
    biztype biz_type;
    buildtype build_type;
    std::string bizname;
    std::string island;
    std::string owner;
    std::vector<std::string> manager;
};

#endif