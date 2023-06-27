#include "signup.h"
#include "data.h"
#include "mainwindow.h"
#include "personal.h"
#include "personal.h"
#include"qfile.h"
#include"QFileDialog"
#include "ui_signup.h"
#include "menu.h"
#include <QApplication>
#include <QLineEdit>
#include <QMessageBox>
#include <QPalette>
#include "file_function.h"
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
    //ui->lineEdit_2->setEchoMode(QLineEdit::Password);


    //QString style = "border: 2px solid red"; // استایلی که برای نمایش خطاها استفاده می‌شود

    if (ui->lineEdit->text().isEmpty()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Do Not Enter Username.");
        msgBox.setText("Please Enter Your Username 🙄");
        msgBox.setIcon(QMessageBox::Critical);

        msgBox.setStyleSheet("QMessageBox { background-color: #3297a8; font-size: 16px; font-weight: bold; }");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);

        // Set the escape button to be the Cancel button


        int ret = msgBox.exec();
        if (ret == QMessageBox::Ok) {
            signup *s=new signup();
            s->setWindowFlags(Qt::CustomizeWindowHint |Qt::FramelessWindowHint);
            s->show();
            this->close();
            return;
        }

        //QPalette pal = msgBox.palette();
        //pal.setColor(QPalette::Window, Qt::red);
        //msgBox.setPalette(pal);

        msgBox.exec();
        //ui->lineEdit->setPlaceholderText("*UserName");
        //ui->lineEdit->setStyleSheet("color::red");

    }

    if (ui->lineEdit_2->text().isEmpty()) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Do Not Enter Password.");
        msgBox.setText("Please Enter Your Password 🙄");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setStyleSheet("QMessageBox { background-color: #3297a8; font-size: 16px; font-weight: bold; }");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);

        // Set the escape button to be the Cancel button


        int ret = msgBox.exec();
        if (ret == QMessageBox::Ok) {
            signup *s=new signup();
            s->setWindowFlags(Qt::CustomizeWindowHint |Qt::FramelessWindowHint);
            s->show();
            this->close();
            return;
        }

        //QPalette pal = msgBox.palette();
        //pal.setColor(QPalette::Window, Qt::red);
        //msgBox.setPalette(pal);

        msgBox.exec();

        //ui->lineEdit_2->setStyleSheet("color::red");
    }
    //QString usernam=ui->lineEdit->text();
    //p.set_username(ui->lineEdit->text());
    //p.set_password(ui->lineEdit_2->text());
    //p.set_firstname(ui->lineEdit_3->text());
    //p.set_lastname(ui->lineEdit_4->text());
    //pair <QString, personal> person(usernam, p);
    //information.insert(person);
    //information.push_back(p);
    //personal per;

    QString filename = "information";
    personal* newp=new personal(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text());
    information.push_back(newp);
    for(auto it=information.begin();it!=information.end();it++){
        file_write(filename,**it);
    }

    menu *a=new menu();
    a->setWindowFlags(Qt::CustomizeWindowHint |Qt::FramelessWindowHint);
    a->show();
    this->close();
  }




void signup::on_pushButton_2_clicked()
{
    menu *a=new menu();
    a->setWindowFlags(Qt::CustomizeWindowHint |Qt::FramelessWindowHint);
    a->show();
    this->close();

}

