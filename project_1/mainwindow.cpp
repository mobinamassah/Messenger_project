#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signup.h"
#include "QVector"
#include <personal.h>
#include"qfile.h"
#include"QFileDialog"
using namespace std;


QVector<personal*> information;

//QVector<data>T;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}




