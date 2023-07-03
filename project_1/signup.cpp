#include "signup.h"
#include "data.h"
#include "mainwindow.h"
#include "personal.h"
#include "personal.h"
#include "private_chat.h"
#include"qfile.h"
#include"QFileDialog"
#include "ui_signup.h"
#include "menu.h"
#include <QApplication>
#include <QLineEdit>
#include <QMessageBox>
#include <QPalette>
#include "file_function.h"
#include "signup_client.h"
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QInputDialog>
using namespace std;

signup::signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("UserName");
    ui->lineEdit_2->setPlaceholderText("Password");
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_3->setPlaceholderText("Firstname");
    ui->lineEdit_4->setPlaceholderText("Lastname");
    //QPushButton *sign_Button = new QPushButton("login");

        net_manager = new QNetworkAccessManager(this);

        connect(net_manager, &QNetworkAccessManager::finished, this, &signup::server_reply);

        //connect(sign_Button, &QPushButton::clicked, this, &signup::login);



}

signup::~signup()
{
    delete ui;
}
void signup::send_request(QString usernam, QString password, QString firstname, QString lastname)
{
    QUrl url("http://api.barafardayebehtar.ml:8080/signup?");
    QUrlQuery query;

    query.addQueryItem("username", usernam);
    query.addQueryItem("password", password);
    query.addQueryItem("firstname", firstname);
    query.addQueryItem("lastname", lastname);
    url.setQuery(query);
    request.setUrl(url);
    net_manager->get(request);
}


void signup::server_reply(QNetworkReply* reply)
{
    QString reply_message = reply->readAll();
    QJsonDocument jDoc = QJsonDocument::fromJson(reply_message.toUtf8());
    QJsonObject jObj = jDoc.object();
    //qDebug()<<jObj["message"].toString();
    //qDebug()<<jObj["code"].toString();
    //if(jObj["code"].toString().compare("200")== 0)
    //{
        QMessageBox msg;
        //msg.setIcon(QMessageBox::Information);
        msg.setIcon(QMessageBox::Information);
        msg.setWindowTitle(jObj["code"].toString());
        msg.setText(jObj["message"].toString()+"😀");
        msg.setIcon(QMessageBox::Information);
        msg.setStyleSheet("QMessageBox { background-color: #3297a8; font-size: 16px; font-weight: bold; }");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setDefaultButton(QMessageBox::Ok);

        // Set the escape button to be the Cancel button


        int ret = msg.exec();
        if (ret == QMessageBox::Ok) {
            menu *s=new menu();
            s->setWindowFlags(Qt::CustomizeWindowHint |Qt::FramelessWindowHint);
            s->show();
            this->close();
            return;
        }

        //QPalette pal = msgBox.palette();
        //pal.setColor(QPalette::Window, Qt::red);
        //msgBox.setPalette(pal);

        msg.exec();

        //QMessageBox::information(nullptr, jObj["code"].toString(),jObj["message"].toString());

   //}
}
void signup::on_pushButton_clicked()
{

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
        QString usernam = ui->lineEdit->text();
        QString password = ui->lineEdit_2->text();
        QString firstname = ui->lineEdit_3->text();
        QString lastname = ui->lineEdit_4->text();

        send_request(usernam,password,firstname,lastname);



        //QObject::connect(&client1, &signup_client::signUpResponse, [&](QString message, QString code) {
            //QString title;
            //if (code.isEmpty()) {
             //   title = "Error";
              //  message = "Error: " + message;
            //} else {
             //   title = "Success";
               // message = "Message: " + message + "\nCode: " + code;
            //}
            //QMessageBox::information(nullptr, title, message);
        //});




                //client1.sign_Up(usernam, password, firstname, lastname);


        //signup_client.sign_Up(username, password, firstname, lastname);

   // QString filename = "information";
    //personal* newp=new personal(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text());
    //information.push_back(newp);
    //for(auto it=information.begin();it!=information.end();it++){
        //file_write(filename,**it);
    //}

    //menu *a=new menu();
    //a->setWindowFlags(Qt::CustomizeWindowHint |Qt::FramelessWindowHint);
    //a->show();
    //this->close();
  }

void signup::on_pushButton_2_clicked()
{
    menu *a=new menu();
    a->setWindowFlags(Qt::CustomizeWindowHint |Qt::FramelessWindowHint);
    a->show();
    this->close();

}

