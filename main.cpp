#include "mainwindow.h"
#include"map.h"
#include <QApplication>
#include<QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QDir::setCurrent(a.applicationDirPath());
    Map* shahe=new Map("DataOfPoint.txt");
    MainWindow w;
    w.show();
    return a.exec();
}
