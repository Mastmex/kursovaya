#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "date.h"
int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/
    date d;
    d.setDate("29.02.68");
    cout<<endl<<d.getDateAmerican();
    d.increaceDay(840);
    cout<<endl<<d.getDateLong();
    return 0;
}
