#ifndef LOG_OUT_H
#define LOG_OUT_H
#include "qjsondocument.h"
#include "qjsonobject.h"
#include "qnetworkaccessmanager.h"
#include "qnetworkrequest.h"
#include <QWidget>

#include <QWidget>

namespace Ui {
class log_out;
}

class log_out : public QWidget
{
    Q_OBJECT
    QNetworkRequest net;
    QJsonDocument ment;
    QJsonObject ject;

public:
    explicit log_out(QWidget *parent = nullptr);
    ~log_out();
    void send(QString _usernam, QString _password);
    void server(QNetworkReply* r);
    QNetworkAccessManager* net_m;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::log_out *ui;
};

#endif // LOG_OUT_H
