#include "signup.h"
#include "data.h"
#include "mainwindow.h"
#include <personal.h>
#include "personal.h"
#include"qfile.h"
#include"QFileDialog"
#include "ui_signup.h"
#include "menu.h"
using namespace std;

signup::signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("UserName");
    ui->lineEdit_2->setPlaceholderText("Password");
    ui->lineEdit_3->setPlaceholderText("Firstname");
    ui->lineEdit_4->setPlaceholderText("Lastname");


}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButton_clicked(){

    //class data d;
    //d.set_username(ui->lineEdit->text());
    //d.set_password(ui->lineEdit_2->text());
   // d.set_firstname(ui->lineEdit_3->text());
   // d.set_lastname(ui->lineEdit_4->text());
   // this->close();
   // MainWindow *w=new MainWindow();
   // w->show();

    string username=ui->lineEdit->text().toStdString();
    class personal p;
    string usernam=ui->lineEdit->text().toStdString();
    p.set_username(ui->lineEdit->text().toStdString());
    p.set_password(ui->lineEdit_2->text().toStdString());
    p.set_firstname(ui->lineEdit_3->text().toStdString());
    p.set_lastname(ui->lineEdit_4->text().toStdString());
    pair <string, personal> person(usernam, p);
    information.insert(person);
    QString filePath = "information.txt";
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        for (auto it = information.begin(); it != information.end(); ++it) {
            out << QString::fromStdString(it->first) << "/" << QString::fromStdString(it->second.get_password()) << "/" <<QString::fromStdString(it->second.get_token())<<QString::fromStdString(it->second.get_firstname())<<QString::fromStdString(it->second.get_lastname())  <<"\n";
        }
        file.close();
    }
     menu *a=new menu();
     a->show();
     this->close();
  }



