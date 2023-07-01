#include "log_out.h"
#include "ui_log_out.h"
#include "mainwindow.h"
#include "menu.h"
#include "personal.h"
#include "qmessagebox.h"
#include <QNetworkReply>
#include <QUrlQuery>
#include "signup.h"
#include "ui_login.h"
#include <QFile>
#include "file_function.h"
#include <selection_page.h>

log_out::log_out(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::log_out)
{
        ui->setupUi(this);
        QString filename="information";
        file_read(filename);
        ui->lineEdit->setPlaceholderText("UserName");
        ui->lineEdit_2->setPlaceholderText("Password");
        net_m = new QNetworkAccessManager(this);

        connect(net_m, &QNetworkAccessManager::finished, this, &::log_out::server);

}

log_out::~log_out()
{
    delete ui;
}
void log_out::send(QString usernam, QString password)
{

    QUrl u("http://api.barafardayebehtar.ml:8080/logout?");


        QUrlQuery q;

    q.addQueryItem("username", usernam);
    q.addQueryItem("password", password);

    u.setQuery(q);
    net.setUrl(u);
    net_m->get(net);
}


void log_out::server(QNetworkReply* r)
{
    QString reply_message = r->readAll();
    QJsonDocument ment = QJsonDocument::fromJson(reply_message.toUtf8());
    QJsonObject ject = ment.object();
    //qDebug()<<jObj["message"].toString();
    //qDebug()<<jObj["code"].toString();
    if(ject["code"].toString().compare("200")== 0){

        for(auto it=information.begin();it!=information.end();it++){
        if((*it)->get_username()==ui->lineEdit->text() && (*it)->get_password()==ui-> lineEdit_2->text()){
            (*it)->set_token(ject["token"].toString());
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
        msg.setWindowTitle(ject["code"].toString());
        msg.setText(ject["message"].toString()+"😀");
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


void log_out::on_pushButton_clicked()
{
        QString _usernam = ui->lineEdit->text();
        QString _password = ui->lineEdit_2->text();


        send(_usernam,_password);
}


void log_out::on_pushButton_2_clicked()
{
    menu *n=new menu();
       n->setWindowFlags(Qt::CustomizeWindowHint |Qt::FramelessWindowHint);
       n->show();
       this->close();

}

