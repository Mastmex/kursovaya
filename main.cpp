#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "date.h"
int between(date d1,date d2);
int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/
    date d,d2;
    d.setDate("05.11.34");
    d2.setDate("12.11.2020");
    cout<<endl<<d.getDateAmerican();
    d.increaceDay(840);
    cout<<endl<<d.getDateLong()<<endl;
    cout<<between(d,d2)<<endl;
    return 0;
}
int between(date d1,date d2)
{
    int i=0;
    if(d1==d2)
        return 0;
    if(d1.getYear()>=d2.getYear()){
        if(d1.getMonth()>=d2.getMonth())
            if(d1.getDay()>d2.getDay())
                goto less;
    }
    else goto more;
    more:
    while(1)
    {
        i++;
        d1.increaceDay();
        if(d1==d2)
            return i;
    }
    less:
    while(1)
    {
        i--;
        d1.decreaceDay();
        if(d1==d2)
            return i;
    }

}
