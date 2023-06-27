#include "login.h"
#include "mainwindow.h"
#include "menu.h"
#include "personal.h"
#include "qmessagebox.h"
#include "signup.h"
#include "ui_login.h"
#include <QFile>
#include "file_function.h"


login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    //ui->setupUi(this);
    QString filename="information";
    file_read(filename);
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
    QMessageBox q;
        for (auto it = information.begin(); it != information.end(); ++it) {
            if((*it)->get_username()==ui->lineEdit->text() && (*it)->get_password()==ui-> lineEdit_2->text()){
                q.setText("Confirmed    ");
                q.exec();
                break;

            }

            else{

                    QMessageBox msgBox;
                    //this->close();
                    msgBox.setWindowTitle("Login failed");
                    msgBox.setText("Username or password is wrong 🙄");
                    msgBox.setIcon(QMessageBox::Critical);

                    msgBox.setStyleSheet("QMessageBox { background-color: #3297a8; font-size: 16px; font-weight: bold; }");
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
        }
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

