#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signup.h"
#include "vector"
#include <personal.h>
#include"qfile.h"
#include"QFileDialog"


multimap <string, personal> information;

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




