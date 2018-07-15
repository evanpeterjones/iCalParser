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

using namespace std;

void printEvent(int year, int month, int day, string name, string time) {
    string str_month;
    switch (month) {
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
}

int main(int argc, const char * argv[]) {
    string DT_Start = "DTSTART:";
    string SUMMARY = "SUMMARY";
    string filename = "/Users/evanpeterjones/Downloads/evan_cal.ics";
    int year, month, day;
    int c_year, c_month, c_day;
    c_year = 2018;
    c_month = 7;
    c_day = 15;
    bool v;
    cout << (v = c_day == 14 ? true : false) << endl;
    string data;
    string summ;
    fstream f;
    f.open(filename);
    std::istream fil(filename);
    
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
        }
    }
    f.close();
    return 0;
}

