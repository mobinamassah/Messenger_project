#include "logout.h"
#include "ui_logout.h"
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
logout::logout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::logout)
{
    ui->setupUi(this);
    QString filename="information";
    file_read(filename);
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("UserName");
    ui->lineEdit_2->setPlaceholderText("Password");
    net_manag = new QNetworkAccessManager(this);

    connect(net_manag, &QNetworkAccessManager::finished, this, &::logout::server_repl);

}

logout::~logout()
{
    delete ui;
}


void logout::send_reques(QString usernam, QString password)
{

    QUrl url("http://api.barafardayebehtar.ml:8080/logout?");


        QUrlQuery query;

    query.addQueryItem("username", usernam);
    query.addQueryItem("password", password);

    url.setQuery(query);
    reque.setUrl(url);
    net_manag->get(reque);
}

void logout::server_repl(QNetworkReply* reply)
{
    QString reply_message = reply->readAll();
    QJsonDocument jDo = QJsonDocument::fromJson(reply_message.toUtf8());
    QJsonObject jOb = jDo.object();
    //qDebug()<<jObj["message"].toString();
    //qDebug()<<jObj["code"].toString();
    if(jOb["code"].toString().compare("200")== 0){

        for(auto it=information.begin();it!=information.end();it++){
        if((*it)->get_username()==ui->lineEdit->text() && (*it)->get_password()==ui-> lineEdit_2->text()){
            (*it)->set_token(jOb["token"].toString());
        }
        }
        QString filename = "information";
        //personal* newp=new personal(ui->lineEdit->text(),ui->lineEdit_2->text(),jOb["token"].toString());
        //information.push_back(newp);
        for(auto it=information.begin();it!=information.end();it++){
         file_write(filename,**it);}

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
           menu *sp=new menu();
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
void logout::on_pushButton_clicked()
{
    QString usernam = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();


    send_reques(usernam,password);
}


void logout::on_pushButton_2_clicked()
{
    menu *a=new menu();
    a->setWindowFlags(Qt::CustomizeWindowHint |Qt::FramelessWindowHint);
    a->show();
    this->close();
}

