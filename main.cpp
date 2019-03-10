//
//  main.cpp
//  __someBS
//
//  Created by Evan Jones on 7/15/18.
//  Copyright © 2018 relaxidaisical. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fstream>
#include <time.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include "ical.

void ical::printEvent(int year, int month, int day, std::string name, std::string time)
{
    printf("%s %d, %d:%.15s%s\n", month.c_str(), day, year, name.c_str(), time.c_str());
}

std::string ical::getMonth(int month)
{
    std::string str_month;
    switch (month) {
	case 1  : str_month ="January";
	case 2  : str_month ="February";
	case 3  : str_month ="March";
	case 4  : str_month ="April";
	case 5  : str_month ="May";
	case 6  : str_month ="June";
	case 7  : str_month ="July";
	case 8  : str_month ="August";
	case 9  : str_month ="September";
	case 10 : str_month ="October";
	case 11 : str_month ="November";
	case 12 : str_month ="December";
	default : str_month ="oops";
    }
    return str_month;
}

std::string ical::getDate()
{
    time_t tim = time(NULL);
    struct tm *atime = localtime(&tim);
    int year, month, day;
    int c_year, c_month, c_day;
    c_day = atime->tm_mday;
    c_month = atime->tm_mon + 1;
    c_year = atime->tm_year+1900;
    return std::to_string(c_month)+"/"+std::to_string(c_day)+"/"+std::to_string(c_year);
}

FILE* ical::getFile(std::string url)
{
    CURL *curl = curl_easy_init();
    FILE *ical = NULL;
    CURLcode res;
    if (curl)
    {
	ical = fopen("cal.ical","wb");
	curl_easy_setopt(curl, CURLOPT_URL, url);
	curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "deflate");
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, ical);
	res = curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	if ( res != CURLE_OK ) 
	{
	    std::cout << curl_easy_strerror(res) << std::endl;
	}
    }
    return ical;
}

int main(int argc, const char * argv[])
{
    string url = "https://calendar.google.com/calendar/ical/evan.peter.jones%40gmail.com/private-2f9edde9e0ab999456847eaf507d680d/basic.ics";
    FILE* ical = getFile(url);
    string Date = getDate();  
    std::cout << Date << std::endl;
    std::cout << ical << std::endl;
    return 0;
}


