#include "menu.h"
#include "log_out.h"
#include "ui_menu.h"
#include "mainwindow.h"
#include "signup.h"
#include "login.h"
menu::menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_clicked()
{
    signup *s=new signup();
    s->setWindowFlags(Qt::CustomizeWindowHint |Qt::FramelessWindowHint);
    s->show();
    hide();

}


void menu::on_pushButton_2_clicked()
{
    login*l=new login();

    l->setWindowFlags(Qt::CustomizeWindowHint |Qt::FramelessWindowHint);
    l->show();
    hide();
}


void menu::on_pushButton_3_clicked()
{
    log_out* g=new log_out();
    g->setWindowFlags(Qt::CustomizeWindowHint |Qt::FramelessWindowHint);
    g->show();
    hide();

}

