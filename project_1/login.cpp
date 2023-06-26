#include "login.h"
#include "menu.h"
#include "qmessagebox.h"
#include "signup.h"
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
    if (ui->lineEdit->text().isEmpty()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Do Not Enter Username.");
        msgBox.setText("Please Enter Your Username 🙄      ");
        msgBox.setStyleSheet("background-color: gray;");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);

        // Set the escape button to be the Cancel button


        int ret = msgBox.exec();
        if (ret == QMessageBox::Ok) {
            login *s=new login();
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
        msgBox.setWindowTitle("Do Not Enter Password.");
        msgBox.setText("Please Enter Your Password 🙄      ");
        msgBox.setStyleSheet("background-color: gray;");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);

        // Set the escape button to be the Cancel button


        int ret = msgBox.exec();
        if (ret == QMessageBox::Ok) {
            login *s=new login();
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
    menu *a=new menu();
    a->setWindowFlags(Qt::CustomizeWindowHint |Qt::FramelessWindowHint);
    a->show();
    this->close();
}


void login::on_pushButton_2_clicked()
{
    menu *a=new menu();
    a->setWindowFlags(Qt::CustomizeWindowHint |Qt::FramelessWindowHint);
    a->show();
    this->close();
}

