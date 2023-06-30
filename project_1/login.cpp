#include "login.h"
#include "mainwindow.h"
#include "menu.h"
#include "personal.h"
#include "qmessagebox.h"
#include "qnetworkreply.h"
#include "qurlquery.h"
#include "signup.h"
#include "ui_login.h"
#include <QFile>
#include "file_function.h"
#include <selection_page.h>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    QString filename="information";
    file_read(filename);
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("UserName");
    ui->lineEdit_2->setPlaceholderText("Password");
    net_manage = new QNetworkAccessManager(this);

    connect(net_manage, &QNetworkAccessManager::finished, this, &::login::server_repl);



}

login::~login()
{
    delete ui;
}

void login::send_reques(QString usernam, QString password)
{

    QUrl url("http://api.barafardayebehtar.ml:8080/login?");


        QUrlQuery query;

    query.addQueryItem("username", usernam);
    query.addQueryItem("password", password);

    url.setQuery(query);
    reques.setUrl(url);
    net_manage->get(reques);
}

void login::server_repl(QNetworkReply* reply)
{
    QString reply_message = reply->readAll();
    QJsonDocument jDo = QJsonDocument::fromJson(reply_message.toUtf8());
    QJsonObject jOb = jDo.object();
    //qDebug()<<jObj["message"].toString();
    //qDebug()<<jObj["code"].toString();
    if(jOb["code"].toString().compare("200")== 0){
        QString filename = "information";
        personal* newp=new personal(ui->lineEdit->text(),ui->lineEdit_2->text(),jOb["token"].toString());
        information.push_back(newp);
        for(auto it=information.begin();it!=information.end();it++){
         file_write(filename,**it);
        }

    }

        QMessageBox msg;
        //msg.setIcon(QMessageBox::Information);
        msg.setIcon(QMessageBox::Information);
        msg.setWindowTitle(jOb["code"].toString());
        msg.setText(jOb["message"].toString()+"😀");
        msg.setIcon(QMessageBox::Information);
        msg.setStyleSheet("QMessageBox { background-color: #3297a8; font-size: 16px; font-weight: bold; }");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setDefaultButton(QMessageBox::Ok);

        // Set the escape button to be the Cancel button


        int ret = msg.exec();
        if (ret == QMessageBox::Ok) {
            Selection_page *sp=new Selection_page();
                            sp->setWindowFlags(Qt::CustomizeWindowHint |Qt::FramelessWindowHint);
                            sp->show();
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
    QString usernam = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();


    send_reques(usernam,password);



    //QMessageBox q;
        //for (auto it = information.begin(); it != information.end(); ++it) {
            //if((*it)->get_username()==ui->lineEdit->text() && (*it)->get_password()==ui-> lineEdit_2->text()){
                //Selection_page *sp=new Selection_page();
                //sp->setWindowFlags(Qt::CustomizeWindowHint |Qt::FramelessWindowHint);
                //sp->show();
                //this->close();
               // break;

           // }

            //else{

                    //QMessageBox msgBox;
                    //this->close();
                    //msgBox.setWindowTitle("Login failed");
                    //msgBox.setText("Username or password is wrong 🙄");
                    //msgBox.setIcon(QMessageBox::Critical);

                    //msgBox.setStyleSheet("QMessageBox { background-color: #3297a8; font-size: 16px; font-weight: bold; }");
                    //msgBox.setStandardButtons(QMessageBox::Ok);
                    //msgBox.setDefaultButton(QMessageBox::Ok);

                    // Set the escape button to be the Cancel button


                    //int ret = msgBox.exec();
                    //if (ret == QMessageBox::Ok) {
                       // login *s=new login();
                        //s->setWindowFlags(Qt::CustomizeWindowHint |Qt::FramelessWindowHint);
                       // s->show();
                       //this->close();
                        //return;
                    //}
        //}
       //}
    //menu *a=new menu();
    //a->setWindowFlags(Qt::CustomizeWindowHint |Qt::FramelessWindowHint);
    //a->show();
    //this->close();
}


void login::on_pushButton_2_clicked()
{

    menu *a=new menu();
    a->setWindowFlags(Qt::CustomizeWindowHint |Qt::FramelessWindowHint);
    a->show();
    this->close();
}

