#ifndef LOGOUT_H
#define LOGOUT_H
#include "qjsondocument.h"
#include "qjsonobject.h"
#include "qnetworkaccessmanager.h"
#include "qnetworkrequest.h"
#include <QWidget>



namespace Ui {
class logout;
}

class logout : public QWidget
{
    Q_OBJECT
    QNetworkRequest reque;
    QJsonDocument jD;
    QJsonObject jO;


public:
    explicit logout(QWidget *parent = nullptr);
    ~logout();
    void send_reques(QString usernam, QString password);
    void server_repl(QNetworkReply* reply);
    QNetworkAccessManager* net_manag;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::logout *ui;
};

#endif // LOGOUT_H
