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

<<<<<<< HEAD
using namespace std;

void printEvent(int year, int month, int day, string name, string time)
{
    string str_month;
    switch (month)
    {
	case 1  : str_month = "January"; break;
	case 2  : str_month = "February";break;
	case 3  : str_month = "March";break;
	case 4  : str_month = "April";break;
	case 5  : str_month = "May";break;
	case 6  : str_month = "June";break;
	case 7  : str_month = "July";break;
	case 8  : str_month = "August";break;
	case 9  : str_month = "September";break;
	case 10 : str_month = "October";break;
	case 11 : str_month = "November";break;
	case 12 : str_month = "December";break;
	default : str_month = "FUCK";break;
    }
    printf("%s %d, %d:%.15s%s\n", str_month.c_str(), day, year, name.c_str(), time.c_str());
=======
std::string getMonth(int month)
{
  switch (month) {
  case 1  : return "January";
  case 2  : return "February";
  case 3  : return "March";
  case 4  : return "April";
  case 5  : return "May";
  case 6  : return "June";
  case 7  : return "July";
  case 8  : return "August";
  case 9  : return "September";
  case 10 : return "October";
  case 11 : return "November";
  case 12 : return "December";
  default : return "FUCK";
  }
>>>>>>> ffb3f6dbb078e5e8ca8729552fc9c20cd411bf3c
}

std::string getDate()
{
<<<<<<< HEAD
    time_t tim = time(NULL);
    struct tm *atime = localtime(&tim);
    int year, month, day;
    int c_year, c_month, c_day;
    c_day = atime->tm_mday;
    c_month = atime->tm_mon + 1;
    c_year = atime->tm_year+1900;
    return to_string(c_month)+"/"+to_string(c_day)+"/"+to_string(c_year);
=======
  time_t tim = time(NULL);
  struct tm *atime = localtime(&tim);
  int year, month, day;
  int c_year, c_month, c_day;
  c_day = atime->tm_mday;
  c_month = atime->tm_mon + 1;
  c_year = atime->tm_year+1900;
  return std::to_string(c_month)+"/"+std::to_string(c_day)+"/"+std::to_string(c_year);
>>>>>>> ffb3f6dbb078e5e8ca8729552fc9c20cd411bf3c
}

FILE * getFile(std::string url)
{
    CURL *curl = curl_easy_init();
    FILE *ical;
    CURLcode res;
    if (curl)
    {
<<<<<<< HEAD
	ical = fopen("cal.ical","wb");
	curl_easy_setopt(curl, CURLOPT_URL, url);
	curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "deflate");
	//curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, ical);
	res = curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	if ( res != CURLE_OK ) 
	{
	    cout << curl_easy_strerror(res) << endl;
	}
	return ical;
    }  
=======
      std::cout << curl_easy_strerror(res) << std::endl;
    }
    return ical;
  }  
>>>>>>> ffb3f6dbb078e5e8ca8729552fc9c20cd411bf3c
}

int main(int argc, const char * argv[])
{
<<<<<<< HEAD

    string url = "https://calendar.google.com/calendar/ical/evan.peter.jones%40gmail.com/private-2f9edde9e0ab999456847eaf507d680d/basic.ics";
    FILE *ical = getFile(url);
    string Date = getDate();  
    std::cout << Date << std::endl;
    std::cout << ical << std::endl;

    /*
      bool v;
      string data;
      string summ;
      fstream f;
      f.open(filename);
      std::istream fil(filename);
=======
  std::string url = "https://calendar.google.com/calendar/ical/evan.peter.jones%40gmail.com/private-2f9edde9e0ab999456847eaf507d680d/basic.ics";
  FILE *ical = getFile(url);
  std::string Date = getDate();
  std::cout << Date << std::endl;
  std::cout << ical << std::endl;


  /*bool v;
  string data;
  string summ;
  fstream f;
  f.open(filename);
  std::istream fil(filename);
>>>>>>> ffb3f6dbb078e5e8ca8729552fc9c20cd411bf3c
    
      if (f.is_open()) { printf("File \"%s\" successfully opened…\n\n", filename.c_str()); }
      while (!f.eof()) {
      //        f >> data;
      std::getline(fil, data, "\n");
      if (((string)data).find(DT_Start)!=std::string::npos) {
      //we find the start date and parse the data into our print method
      year = stoi(data.substr(8,4));
      month = stoi(data.substr(12, 2));
      day = stoi(data.substr(14,2));
      do {
      //read next line
      //                f >> data;
      std::getline(fil, data, "\n");
      if (data.find(SUMMARY) != std::string::npos) {
      summ = data.substr((data.find_last_of(":")+1));
      //                    printEvent(year, month, day, summ);
      }
      } while (data.find(SUMMARY) == std::string::npos);//this means while the value doesn't match we run;
<<<<<<< HEAD
      }
      }
      f.close();*/
    return 0;
=======
    }
  }
  f.close();*/
  return 0;
>>>>>>> ffb3f6dbb078e5e8ca8729552fc9c20cd411bf3c
}


