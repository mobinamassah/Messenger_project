#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signup.h"
#include "vector"
#include "data.h"

QVector<data>T;

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


void MainWindow::on_pushButton_clicked()
{
    signup *s=new signup();
    s->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    s->show();
    hide();

}

