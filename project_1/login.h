#ifndef LOGIN_H
#define LOGIN_H

#include "qjsondocument.h"
#include "qjsonobject.h"
#include "qnetworkaccessmanager.h"
#include "qnetworkrequest.h"
#include <QWidget>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT
        QNetworkRequest reques;
        QJsonDocument jDo;
        QJsonObject jOb;

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
     void send_reques(QString usernam, QString password);
     void server_repl(QNetworkReply* reply);
     QNetworkAccessManager* net_manage;


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
