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
<<<<<<< HEAD
        void send_reques(QString usernam, QString password);
        void server_repl(QNetworkReply* reply);
        QNetworkAccessManager* net_manage;
=======
     void send_reques(QString usernam, QString password);
     void server_repl(QNetworkReply* reply);
     QNetworkAccessManager* net_manage;
>>>>>>> 3dcb093034070247bfa4742d52556b7fcc2a9515


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
