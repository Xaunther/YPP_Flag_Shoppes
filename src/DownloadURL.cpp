//Implementation of DownloadURL function, which downloads an URL into a file
//The name of the file is automatically defined from the URL

//C++ libraries
#include <stdio.h>
#include <string>
#include <iostream>
//External libraries
#include <curl/curl.h>
//Project files
#include "Write_Data.h"
#include "DownloadURL.h"

std::string DownloadURL(std::string URL)
{
    //Initialize CURL
    CURL *curl_handle;
    FILE *pagefile;
    curl_global_init(CURL_GLOBAL_ALL);

    /* init the curl session */
    curl_handle = curl_easy_init();

    /* set URL to get here */
    curl_easy_setopt(curl_handle, CURLOPT_URL, URL);

    /* Switch on full protocol/debug output while testing */
    curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 0L);

    /* disable progress meter, set to 0L to enable it */
    curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 0L);

    /* send all data to this function  */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, Write_Data);

    /* open the file */
    pagefile = fopen(("downloads/" + FilenameFromURL(URL)).c_str(), "wb");
    if (pagefile)
    {
        /* write the page body to this file handle */
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, pagefile);

        /* get it! */
        curl_easy_perform(curl_handle);

        /* close the header file */
        fclose(pagefile);
    }

    /* cleanup curl stuff */
    curl_easy_cleanup(curl_handle);

    curl_global_cleanup();

    return "downloads/" + FilenameFromURL(URL);
}

//Function to get a unique filename from a URL fom ypp
std::string FilenameFromURL(std::string URL)
{
    //Slight differences depending on the type of webpage
    if (URL.find("yoweb/flag/info.wm") != std::string::npos) //Flag page
    {
        //Name example: flagid=10006353& -> flag_10006353.html
        return "flag_" + URL.substr(URL.find("flagid=") + 7, URL.find("&", URL.find("flagid=") + 7) - URL.find("flagid=") - 7) + ".html";
    }
    else if (URL.find("yoweb/crew/info.wm") != std::string::npos) //Crew page
    {
        //Name example: crewid=10006353& -> crew_10006353.html
        return "crew_" + URL.substr(URL.find("crewid=") + 7, URL.find("&", URL.find("crewid=") + 7) - URL.find("crewid=") - 7) + ".html";
    }
    else if (URL.find("yoweb/pirate/info.wm") != std::string::npos) //Pirate page
    {
        //Name example: target=Xaunder -> pirate_Xaunder.html
        return "pirate_" + URL.substr(URL.find("target=") + 7) + ".html";
    }
    else //This type of webpage is not recognized. ABORT
    {
        std::cerr << URL << " is not a suitable webpage" << std::endl;
        exit(1);
    }
}