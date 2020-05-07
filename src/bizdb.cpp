//Implementation file for bizdb class

//Project files
#include "bizdb.h"
#include "biz.h"
#include "pirate.h"
#include "crew.h"
#include "flag.h"
#include <ostream>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

void bizdb::RegisterBiz(flag _flag)
{
    for (unsigned int i = 0; i < _flag.GetCrewList().size(); i++)
        bizdb::RegisterBiz(_flag.GetCrewList()[i]);
}
void bizdb::RegisterBiz(crew _crew)
{
    for (unsigned int i = 0; i < _crew.GetPirateList().size(); i++)
        bizdb::RegisterBiz(_crew.GetPirateList()[i]);
}
void bizdb::RegisterBiz(pirate _pirate)
{
    for (unsigned int i = 0; i < _pirate.GetBizList().size(); i++)
        bizdb::RegisterBiz(_pirate.GetBizList()[i]);
}
void bizdb::RegisterBiz(biz _biz)
{
    //We only register new businesses. If it exists, we update the manager/owner info
    for (unsigned int i = 0; i < this->bizlist.size(); i++)
    {
        //If it exists, update
        if (_biz.GetBizName() == this->bizlist[i].GetBizName() && _biz.GetIslandName() == this->bizlist[i].GetIslandName())
        {
            this->bizlist[i].Update(_biz);
            return;
        }
    }
    //If no matching biz was found, add new!
    this->bizlist.push_back(_biz);
}
void bizdb::Print()
{
    bizdb::Print(std::cout);
}
void bizdb::PrintXML()
{
    bizdb::PrintXML(std::cout);
}

void bizdb::Print(std::string filename)
{
    std::ofstream outf;
    outf.open(filename.c_str());
    if (!outf)
        return;
    bizdb::Print(outf);
    outf.close();
}
void bizdb::PrintXML(std::string filename)
{
    std::ofstream outf;
    outf.open(filename.c_str());
    if (!outf)
        return;
    bizdb::PrintXML(outf);
    outf.close();
}

void bizdb::Print(std::ostream &stream)
{
    //Print header
    stream << std::setw(34) << "Business Name"
           << " | ";
    stream << std::setw(32) << "Island"
           << " | ";
    stream << std::setw(13) << "Type"
           << " | ";
    stream << std::setw(16) << "Owner"
           << " | ";
    stream << "Managers" << std::endl;
    //Print each biz
    for (unsigned int i = 0; i < this->bizlist.size(); i++)
    {
        stream << std::setw(34) << this->bizlist[i].GetBizName() << " | ";
        stream << std::setw(32) << this->bizlist[i].GetIslandName() << " | ";
        stream << std::setw(13) << this->bizlist[i].GetBizTypeString() << " | ";
        stream << std::setw(16) << this->bizlist[i].GetOwnerName() << " | ";
        for (unsigned j = 0; j < this->bizlist[i].GetManagerName().size(); j++)
        {
            stream << this->bizlist[i].GetManagerName()[j];
            if (j < this->bizlist[i].GetManagerName().size() - 1)
                stream << ", ";
        }
        stream << std::endl;
    }
}

void bizdb::PrintXML(std::ostream &stream)
{
    //Print each part of the HTML file
    stream << "<!DOCTYPE html>" << std::endl;
    stream << "<html>" << std::endl;
    bizdb::PrintXML_Header(stream);
    bizdb::PrintXML_Body(stream);
    stream << "</html>" << std::endl;
}

void bizdb::PrintXML_Header(std::ostream &stream)
{
    //Prints the header
    stream << "<head>" << std::endl;
    stream << "<title>List of Shoppes and Stalls</title>" << std::endl;
    stream << "<style>" << std::endl;
    stream << "table {" << std::endl;
    stream << "border-spacing: 0;" << std::endl;
    stream << "width: 100%;" << std::endl;
    stream << "border: 1px solid #ddd;" << std::endl;
    stream << "}" << std::endl;
    stream << std::endl;
    stream << "th {" << std::endl;
    stream << "cursor: pointer;" << std::endl;
    stream << "}" << std::endl;
    stream << std::endl;
    stream << "th, td {" << std::endl;
    stream << "text-align: left;" << std::endl;
    stream << "padding: 16px;" << std::endl;
    stream << "}" << std::endl;
    stream << std::endl;
    stream << "tr:nth-child(even) {" << std::endl;
    stream << "background-color: #f2f2f2" << std::endl;
    stream << "}" << std::endl;
    stream << "</style>" << std::endl;
    stream << "</head>" << std::endl;
}

void bizdb::PrintXML_Body(std::ostream &stream)
{
    stream << "<body>" << std::endl;
    bizdb::PrintXML_Table(stream);
    bizdb::PrintXML_Script(stream);
    stream << "</body>" << std::endl;
}

void bizdb::PrintXML_Table(std::ostream &stream)
{
    //Table header
    stream << "<table id=\"BizTable\">" << std::endl;
    stream << "<tr>" << std::endl;
    stream << "<th onclick=\"sortTable(0)\">Business Name</th>" << std::endl;
    stream << "<th onclick=\"sortTable(1)\">Island</th>" << std::endl;
    stream << "<th onclick=\"sortTable(2)\">Type</th>" << std::endl;
    stream << "<th onclick=\"sortTable(3)\">Owner</th>" << std::endl;
    stream << "<th onclick=\"sortTable(4)\">Managers</th>" << std::endl;
    stream << "</tr>" << std::endl;
    //Print the contents now for each biz
    for (unsigned int i = 0; i < this->bizlist.size(); i++)
    {
        stream << "<tr>" << std::endl;
        stream << "<td>" << this->bizlist[i].GetBizName() << "</td>" << std::endl;
        stream << "<td>" << this->bizlist[i].GetIslandName() << "</td>" << std::endl;
        stream << "<td>" << this->bizlist[i].GetBizTypeString() << "</td>" << std::endl;
        stream << "<td>" << this->bizlist[i].GetOwnerName() << "</td>" << std::endl;
        stream << "<td>";
        for (unsigned j = 0; j < this->bizlist[i].GetManagerName().size(); j++)
        {
            stream << this->bizlist[i].GetManagerName()[j];
            if (j < this->bizlist[i].GetManagerName().size() - 1)
                stream << ", ";
        }
        stream << "</td>" << std::endl;
        stream << "</tr>" << std::endl;
    }
    stream << "</table>" << std::endl;
}

void bizdb::PrintXML_Script(std::ostream &stream)
{
    //Puke here the javascript to sort the tables
    stream << "<script>" << std::endl;
    stream << "function sortTable(n) {" << std::endl;
    stream << "var table, rows, switching, i, x, y, shouldSwitch, asc, switchcount = 0;" << std::endl;
    stream << "table = document.getElementById(\"BizTable\");" << std::endl;
    stream << "switching = true;" << std::endl;
    stream << "asc = true; " << std::endl;
    stream << "while (switching) {" << std::endl;
    stream << "switching = false;" << std::endl;
    stream << "rows = table.rows;" << std::endl;
    stream << "for (i = 1; i < (rows.length - 1); i++) {" << std::endl;
    stream << "shouldSwitch = false;" << std::endl;
    stream << "x = rows[i].getElementsByTagName(\"TD\")[n];" << std::endl;
    stream << "y = rows[i + 1].getElementsByTagName(\"TD\")[n];" << std::endl;
    stream << "if (asc) {" << std::endl;
    stream << "if (x.innerHTML.toLowerCase() > y.innerHTML.toLowerCase()) {" << std::endl;
    stream << "shouldSwitch= true;" << std::endl;
    stream << "break;" << std::endl;
    stream << "}" << std::endl;
    stream << "} else {" << std::endl;
    stream << "if (x.innerHTML.toLowerCase() < y.innerHTML.toLowerCase()) {" << std::endl;
    stream << "shouldSwitch = true;" << std::endl;
    stream << "break;" << std::endl;
    stream << "}" << std::endl;
    stream << "}" << std::endl;
    stream << "}" << std::endl;
    stream << "if (shouldSwitch) {" << std::endl;
    stream << "rows[i].parentNode.insertBefore(rows[i + 1], rows[i]);" << std::endl;
    stream << "switching = true;" << std::endl;
    stream << "switchcount ++;" << std::endl;
    stream << "} else {" << std::endl;
    stream << "if (switchcount == 0 && asc) {" << std::endl;
    stream << "asc = false;" << std::endl;
    stream << "switching = true;" << std::endl;
    stream << "}" << std::endl;
    stream << "}" << std::endl;
    stream << "}" << std::endl;
    stream << "}" << std::endl;
    stream << "</script>" << std::endl;
}