#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<iostream>
#include<map>
#include<windows.h>
#include<algorithm>
#include <QMainWindow>
#include <personal.h>
using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
//class personal {
//public:
    //string password;
   // string token;
//};
extern multimap <string, personal> information;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
