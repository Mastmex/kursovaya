#ifndef DATE_H
#define DATE_H
#include <string>
#include <string.h>
#include <iostream>
using namespace std;
class date
{
private:
    unsigned short day;
    unsigned short month;
    unsigned int year;
    bool zero=false;
    bool dataCheck(unsigned short d,unsigned short m,unsigned short y);
public:
    date();
    bool setDate(string data);
    string getDate();
    string getDateLong();
    string getDateAmerican();
    void increaceDay();
    void increaceDay(unsigned int d);
    void decreaceDay();
    void decreaceDay(unsigned int d);
    unsigned short weekFinder();
    unsigned short weekFinder2();
    bool operator==(const date &d1);
    unsigned short getDay(){return this->day;}
    unsigned short getMonth(){return this->month;}
    unsigned int getYear(){return this->year;}
};

#endif // DATE_H
