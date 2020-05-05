//Implementation file for biz class

//C++ headers
#include <iostream>
//Project files
#include "biz.h"

//Initialize empty strings with default constructor
biz::biz() : biz_type(biztype::None),
             build_type(buildtype::None),
             bizname(""),
             island(""),
             owner("")
{
}

void biz::SetBizType(std::string _biz_type)
{
    if (_biz_type == "apothecary")
        this->biz_type = biztype::Apothecary;
    else if (_biz_type == "construction")
        this->biz_type = biztype::Construction;
    else if (_biz_type == "distillery")
        this->biz_type = biztype::Distillery;
    else if (_biz_type == "estateagent")
        this->biz_type = biztype::Estate_Agent;
    else if (_biz_type == "fort")
        this->biz_type = biztype::Fort;
    else if (_biz_type == "furnisher")
        this->biz_type = biztype::Furnisher;
    else if (_biz_type == "inn")
        this->biz_type = biztype::Inn;
    else if (_biz_type == "ironmonger")
        this->biz_type = biztype::Iron_Monger;
    else if (_biz_type == "markethall")
        this->biz_type = biztype::Market_Hall;
    else if (_biz_type == "palace")
        this->biz_type = biztype::Palace;
    else if (_biz_type == "shipyard")
        this->biz_type = biztype::Shipyard;
    else if (_biz_type == "tailor")
        this->biz_type = biztype::Tailor;
    else if (_biz_type == "weavery")
        this->biz_type = biztype::Weavery;
    else
        this->biz_type = biztype::None;
}

std::string biz::GetBizTypeString()
{
    switch (this->GetBizType())
    {
    case biztype::None:
        return "";
    case biztype::Apothecary:
        return "Apothecary";
    case biztype::Construction:
        return "Construction";
    case biztype::Distillery:
        return "Distillery";
    case biztype::Estate_Agent:
        return "Estate Agent";
    case biztype::Fort:
        return "Fort";
    case biztype::Furnisher:
        return "Furnisher";
    case biztype::Inn:
        return "Inn";
    case biztype::Iron_Monger:
        return "Iron Monger";
    case biztype::Market_Hall:
        return "Market Hall";
    case biztype::Palace:
        return "Palace";
    case biztype::Shipyard:
        return "Shipyard";
    case biztype::Tailor:
        return "Tailor";
    case biztype::Weavery:
        return "Weavery";
    default:
        return "";
    }
}

void biz::Update(biz _biz)
{
    //Add owner, if applicable
    if (_biz.GetOwnerName() != "")
        this->SetOwner(_biz.GetOwnerName());
    //Append managers
    for (unsigned int i = 0; i < _biz.GetManagerName().size(); i++)
    {
        this->AddManager(_biz.GetManagerName()[i]);
    }
}