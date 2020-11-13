#include "date.h"

date::date()
{
    this->zero=false;
    this->setDate("21/11/2001");
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
    return true;
}
    else{
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
    for(unsigned int i=0;i<d;i++)
        this->increaceDay();
    return;
}
void date::decreaceDay()
{
    this->day--;
    if(day==0)
    {
        if(this->month==2||this->month==4||this->month==6||this->month==9||this->month==8||this->month==11)
        {
            this->day=31;
            this->month--;
            return;
        }
        if(this->month==5||this->month==7||this->month==10||this->month==12)
        {
            this->day=30;
            this->month--;
            return;
        }
        if(this->month==3)
        {
            if((this->year%4)!=0)
            {
                this->month--;
                this->day=28;
                return;
            }
            else
            {
                this->month--;
                this->day=29;
                return;
            }
        }
        if(this->month==1)
        {
            this->month=12;
            this->year--;
            this->day=31;
            return;
        }
    }
}
void date::decreaceDay(unsigned int d)
{
    for(unsigned int i =0;i<d;i++)
        this->decreaceDay();
}
bool date::operator==(const date &d1)
{
    return (d1.day==this->day&&d1.year==this->year&&d1.month==this->month);
}
unsigned short date::weekFinder()
{
    int yCode=0,mCode=0,delta=0,y=0,last;
    last=this->year%100;
    if(this->year%4==0)
        if(this->month<=2)
            delta=1;
    switch ((this->year/100)%4) {
    case 0:
        y=6;
        break;
    case 1:
        y=4;
        break;
    case 2:
        y=2;
        break;
    case 3:
        y=0;
        break;
    }
    switch (this->month) {
    case 1:
        mCode=1;
        break;
    case 2:
        mCode=4;
        break;
    case 3:
        mCode=4;
        break;
    case 4:
        mCode =0;
        break;
    case 5:
        mCode=2;
        break;
    case 6:
        mCode=5;
        break;
    case 7:
        mCode=0;
        break;
    case 8:
        mCode=3;
        break;
    case 9:
        mCode=6;
        break;
    case 10:
        mCode=1;
        break;
    case 11:
        mCode=4;
        break;
    case 12:
        mCode=6;
        break;
    }
    yCode=(y+last+((last)/4))%7;
    return ((delta+(this->day+mCode+yCode)%7)+6)%7;
}
