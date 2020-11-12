#include "date.h"

date::date()
{
    this->zero=false;
}
bool date::setDate(string data)
{
    unsigned short d=0,m=0,y=0;
    char l='d';
    int yearZeros=0;
    char * dateChar;
    int c;
    dateChar= new char[c=data.length()+1];
    strcpy(dateChar,data.c_str());
    ///Ввод
    for(int i=0;i<c;i++)
    {
        if(dateChar[i]>='0'&&dateChar[i]<='9')
            switch (l) {
                case 'd':
                {
                    d*=10;
                    d+=dateChar[i]-'0';
                    break;
                }
                case 'm':
                {
                    m*=10;
                    m+=dateChar[i]-'0';
                    break;
                }
                case 'y':
                {
                    if(dateChar[i]=='0'&&y==0)
                        yearZeros++;
                    y*=10;
                    y+=dateChar[i]-'0';
                    break;
                }
            }
        else
            switch (l) {
                case 'd':
                {
                    l='m';
                    break;
                }
                case 'm':
                {
                    l='y';
                    break;
                }
            }
    }
    if(this->dataCheck(d,m,y))
        {
    if(y<20&&yearZeros<=1)
    {
        y+=2000;
        goto next;
    }
    else
    if(y<100&&y>20)
    {
        y+=1900;
        goto next;
    }
    else
    this->zero=true;
    next:
    this->day=d;
    this->year=y;
    this->month=m;
    cout<<"Date Correct";
    return true;
}
    else{
    cout<<"Date Incorrect";
    return false;
   }
    ///end
    {
        delete dateChar;
    }
}
bool date::dataCheck(unsigned short d, unsigned short m, unsigned short y)
{
    if(m>12||m<1)
        return false;
    if(d<1||d>31)
        return false;
    if(m==4||m==6||m==9||m==11)
        if(d==31)
            return false;
    if(y%4!=0){
        if(m==2)
            if(d>28)
                return false;
    }
    else
        if(m==2)
            if(d>29)
                return false;
    return true;
}
string date::getDate()
{
    char out[]="21/11/01";
    unsigned short d1,d2,m1,m2,y1,y2,d,m,y;
    d=this->day;
    y=this->year;
    m=this->month;
    d2=d%10;
    d/=10;
    d1=d%10;
    m2=m%10;
    m/=10;
    m1=m%10;
    y2=y%10;
    y/=10;
    y1=y%10;
    out[0]=d1+'0';
    out[1]=d2+'0';
    out[2]='/';
    out[3]=m1+'0';
    out[4]=m2+'0';
    out[5]='/';
    out[6]=y1+'0';
    out[7]=y2+'0';
    string a(out);
    return a;
}
string date::getDateLong()
{
    char out[]="21/11/2001";
    unsigned short d1,d2,m1,m2,y1,y2,y3,y4,d,m,y;
    d=this->day;
    y=this->year;
    m=this->month;
    d2=d%10;
    d/=10;
    d1=d%10;
    m2=m%10;
    m/=10;
    m1=m%10;
    y4=y%10;
    y/=10;
    y3=y%10;
    y/=10;
    y2=y%10;
    y/=10;
    y1=y%10;
    out[0]=d1+'0';
    out[1]=d2+'0';
    out[2]='/';
    out[3]=m1+'0';
    out[4]=m2+'0';
    out[5]='/';
    out[6]=y1+'0';
    out[7]=y2+'0';
    out[8]=y3+'0';
    out[9]=y4+'0';
    string a(out);
    return a;
}
string date::getDateAmerican()
{
    char out[]="21/11/2001";
    unsigned short d1,d2,m1,m2,y1,y2,y3,y4,d,m,y;
    d=this->day;
    y=this->year;
    m=this->month;
    d2=d%10;
    d/=10;
    d1=d%10;
    m2=m%10;
    m/=10;
    m1=m%10;
    y4=y%10;
    y/=10;
    y3=y%10;
    y/=10;
    y2=y%10;
    y/=10;
    y1=y%10;
    out[3]=d1+'0';
    out[4]=d2+'0';
    out[2]='/';
    out[0]=m1+'0';
    out[1]=m2+'0';
    out[5]='/';
    out[6]=y1+'0';
    out[7]=y2+'0';
    out[8]=y3+'0';
    out[9]=y4+'0';
    string a(out);
    return a;
}
void date::increaceDay()
{
    this->day++;
    if(this->month==4||this->month==6||this->month==9||this->month==11)
        if(this->day==31)
        {
            this->day=1;
            this->month++;
            return;
        }
    if(this->month==1||this->month==3||this->month==5||this->month==7||this->month==8||this->month==10)
    {
        if(this->day==32)
        {
            this->day=1;
            this->month++;
            return;
        }
    }
    if(this->month==12)
    {
        if(this->day==32)
        {
            this->day=1;
            this->month=1;
            this->year++;
            return;
        }
    }
    if((this->year)%4!=0)
        if(this->month==2)
            if(this->day==29)
            {
                this->day=1;
                this->month++;
                return;
            }
    if((this->year)%4==0)
        if(this->month==2)
            if(this->day==30)
            {
                this->day=1;
                this->month++;
                return;
            }
}
void date::increaceDay(unsigned int d)
{
    for(int i=0;i<d;i++)
    {
    this->day++;
    if(this->month==4||this->month==6||this->month==9||this->month==11)
        if(this->day==31)
        {
            this->day=1;
            this->month++;
            continue;
        }
    if(this->month==1||this->month==3||this->month==5||this->month==7||this->month==8||this->month==10)
    {
        if(this->day==32)
        {
            this->day=1;
            this->month++;
            continue;
        }
    }
    if(this->month==12)
    {
        if(this->day==32)
        {
            this->day=1;
            this->month=1;
            this->year++;
            continue;
        }
    }
    if((this->year)%4!=0)
        if(this->month==2)
            if(this->day==29)
            {
                this->day=1;
                this->month++;
                continue;
            }
    if((this->year)%4==0)
        if(this->month==2)
            if(this->day==30)
            {
                this->day=1;
                this->month++;
                continue;
            }
    }
    return;
}
