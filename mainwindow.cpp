#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
int MainWindow::between(date d1,date d2)
{
    int i=0;
    if(d1==d2)
        return 0;
    if(d1.getYear()>d2.getYear())
        goto less;
    if(d1.getYear()==d2.getYear()&&d1.getMonth()>d2.getMonth())
        goto less;
    if(d1.getYear()==d2.getYear()&&d1.getMonth()==d2.getMonth()&&d1.getDay()>d2.getDay())
        goto less;
    goto more;
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

void MainWindow::on_pushButton_clicked()
{
    QString l = ui->textEdit->toPlainText();
    if( l=="")
    {
        l="21.11.2001";
    }
    if(this->d1.setDate(l.toUtf8().constData()))
    {
        this->setData();
        return;
    }
    else{
        this->ui->textEdit->clear();
        QMessageBox::critical(this,"Ошибка","Введена неправильная дата");
    }

}
void MainWindow::setData()
{
    this->ui->label_8->setText(QString::fromStdString(this->d1.getDate()));
    this->ui->label_10->setText(QString::fromStdString(this->d1.getDateAmerican()));
    this->ui->label_9->setText(QString::fromStdString(this->d1.getDateLong()));
    this->ui->label_16->setText(numToQString(d1));
    this->ui->textEdit->clear();
}
void MainWindow::setData2()
{
    this->ui->label_11->setText(QString::fromStdString(this->d2.getDate()));
    this->ui->label_12->setText(QString::fromStdString(this->d2.getDateLong()));
    this->ui->label_13->setText(QString::fromStdString(this->d2.getDateAmerican()));
    this->ui->label_17->setText(numToQString(d2));
    this->ui->textEdit_3->clear();
}

void MainWindow::on_pushButton_2_clicked()
{
    int d=this->ui->spinBox->value();
    if(d<=1)
        this->d1.decreaceDay();
    else
        this->d1.decreaceDay(d);
    this->setData();
}

void MainWindow::on_pushButton_3_clicked()
{
    int d=this->ui->spinBox_2->value();
    if(d<=1)
        this->d1.increaceDay();
    else
        this->d1.increaceDay(d);
    this->setData();
}

void MainWindow::on_pushButton_6_clicked()
{
    QString l = ui->textEdit_3->toPlainText();
    if( l=="")
    {
        l="21.11.2001";
    }
    if(this->d2.setDate(l.toUtf8().constData())){
        this->setData2();
        return;
    }
    else
    {
        this->ui->textEdit_3->clear();
        QMessageBox::critical(this,"Ошибка","Введена неверная дата");
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    int d=this->ui->spinBox_3->value();
    if(d<=1)
        this->d2.decreaceDay();
    else
        this->d2.decreaceDay(d);
    this->setData2();
}

void MainWindow::on_pushButton_5_clicked()
{
    int d=this->ui->spinBox_4->value();
    if(d<=1)
        this->d2.increaceDay();
    else
        this->d2.increaceDay(d);
    this->setData2();
}

void MainWindow::on_pushButton_7_clicked()
{
    string l= std::to_string(abs(this->between(d1,d2)));
    if((abs(this->between(d1,d2))%100>10&&abs(this->between(d1,d2))%100<20)||abs(this->between(d1,d2))%10==5||abs(this->between(d1,d2))%10==6||abs(this->between(d1,d2))%10==6||abs(this->between(d1,d2))%10==7||abs(this->between(d1,d2))%10==8||abs(this->between(d1,d2))%10==9||abs(this->between(d1,d2))%10==0)
        l+=" дней";
    else if(abs(this->between(d1,d2))%10==1)
        l+=" день";
    else
        l+=" дня";
    this->ui->label_4->setText(QString::fromStdString(l));
}
QString MainWindow::numToQString(date d)
{
    string l;
    switch (d.weekFinder2()) {
        case 0:
        l="Воскресенье";
        break;
    case 1:
    l="Понедельник";
    break;
    case 2:
    l="Вторник";
    break;
    case 3:
    l="Среда";
    break;
    case 4:
    l="Четверг";
    break;
    case 5:
    l="Пятница";
    break;
    case 6:
    l="Суббота";
    break;
    }
    return QString::fromStdString(l);
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    if(arg1==1)
        this->ui->pushButton_2->setText("Убавить день");
    else
        this->ui->pushButton_2->setText("Убавить дни");
}

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    if(arg1==1)
        this->ui->pushButton_3->setText("Добавить день");
    else
        this->ui->pushButton_3->setText("Добавить дни");
}

void MainWindow::on_spinBox_3_valueChanged(int arg1)
{
    if(arg1==1)
        this->ui->pushButton_4->setText("Убавить день");
    else
        this->ui->pushButton_4->setText("Убавить дни");
}

void MainWindow::on_spinBox_4_valueChanged(int arg1)
{
    if(arg1==1)
        this->ui->pushButton_5->setText("Добавить день");
    else
        this->ui->pushButton_5->setText("Добавить дни");
}
