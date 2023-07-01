#ifndef SIGNUP_CLIENT_H
#define SIGNUP_CLIENT_H
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>


class signup_client : public QObject
{
    Q_OBJECT

public:
    explicit signup_client(QObject *parent = nullptr);
    //void sign_Up(const QString &username, const QString &password, const QString &firstname, const QString &lastname);


signals:
    void signUpResponse(QString message, QString code);

public slots:
    void signـUp(QString username, QString password, QString firstname, QString lastname);

private:
    QNetworkAccessManager m_networkManager;

//signals:
     //void signUpSuccess(const QString &message, const QString &code);
     //void signUpError(const QString &errorMessage);

//private slots:
     //void onSignUpReplyFinished(QNetworkReply* reply);


//private:

    //QNetworkAccessManager m_networkManager;
};

#endif // SIGNUP_CLIENT_H


