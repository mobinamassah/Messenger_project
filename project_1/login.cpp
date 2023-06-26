#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("UserName");
    ui->lineEdit_2->setPlaceholderText("Password");

}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{

}

