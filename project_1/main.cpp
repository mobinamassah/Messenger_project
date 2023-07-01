#include "mainwindow.h"
#include "menu.h"
#include <QApplication>
#include <QMainWindow>
#include <QFile>
#include<QVector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menu w;
    w.setWindowFlags(Qt::CustomizeWindowHint |Qt::FramelessWindowHint);
    //w.setMenuBar(nullptr);
    w.show();


    return a.exec();
}

