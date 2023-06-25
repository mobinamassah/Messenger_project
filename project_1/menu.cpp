#include "menu.h"
#include "ui_menu.h"
#include "mainwindow.h"
#include "signup.h"

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
    s->show();
    hide();


}

