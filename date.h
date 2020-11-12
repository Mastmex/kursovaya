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
    unsigned short year;
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
};

#endif // DATE_H
