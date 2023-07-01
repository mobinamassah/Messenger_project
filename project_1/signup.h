#ifndef SIGNUP_H
#define SIGNUP_H

#include "qjsondocument.h"
#include "qjsonobject.h"
#include "qnetworkaccessmanager.h"
#include "qnetworkrequest.h"
#include <QWidget>

namespace Ui {
class signup;
}

class signup : public QWidget
{
    Q_OBJECT
    QNetworkRequest request;
    QJsonDocument jDoc;
    QJsonObject jObj;

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();
    void send_request(QString usernam, QString password, QString firstname, QString lastname);
    void server_reply(QNetworkReply* reply);
    QNetworkAccessManager* net_manager;
    //void sign();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::signup *ui;
};

#endif // SIGNUP_H
