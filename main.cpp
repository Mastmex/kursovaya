#include "mainwindow.h"
#include <QApplication>
#include "date.h"
int between(date d1,date d2);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    /*date d,d2,d3;
    d.setDate("05.11.34");
    d2.setDate("12.11.2020");
    d3.setDate("22.11.1971");
    cout<<endl<<d.getDateAmerican();
    d.increaceDay(840);
    cout<<endl<<d.getDateLong()<<endl;
    cout<<between(d,d2)<<endl;
    cout<<d3.weekFinder();
    return 0;*/
}
