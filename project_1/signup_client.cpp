#include "signup_client.h"
#include "ui_signup_client.h"
#include <QCoreApplication>
#include <QDebug>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QMessageBox>
//signup_client::signup_client(QObject *parent) : QObject(parent)
//{
  //connect(&m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onSignUpReplyFinished(QNetworkReply*)));
//}






//void signup_client::sign_Up(const QString &username, const QString &password, const QString &firstname, const QString &lastname)
//{
        //QString requestUrl = "http://api.barafardayebehtar.ml:8080/signup?";
        //requestUrl += "&username=" + username;
        //requestUrl += "&password=" + password;
        //requestUrl += "&firstname=" + firstname;
        //requestUrl += "&lastname=" + lastname;

        //QNetworkReply *reply = networkManager->get(QNetworkRequest(QUrl(requestUrl)));
         //QNetworkReply* reply = m_networkManager.get(QNetworkRequest(QUrl(requestUrl)));
        //reply->setProperty("requestType", "signUp");
    // Set up the request URL
    //QUrl url("http://api.barafardayebehtar.ml:8080/signup");

    // Create a query string with the parameters
    //QUrlQuery query;
    //query.addQueryItem("username", username);
    //query.addQueryItem("password", password);
    //query.addQueryItem("firstname", firstname);
    //query.addQueryItem("lastname", lastname);

    // Append the query to the URL
   // url.setQuery(query);

    // Create a network request with the URL
    //QNetworkRequest request(url);

    // Send the request and get the reply

//}









signup_client::signup_client(QObject *parent) : QObject(parent)
{
connect(&m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onSignUpReplyFinished(QNetworkReply*)));
}

void signup_client::signـUp(QString usernam, QString password, QString firstname, QString lastname)
{
    // Set up the request URL
    QString requestUrl = "http://api.barafardayebehtar.ml:8080/signup";
    requestUrl += "username=" + usernam;
    requestUrl += "password=" + password;
    requestUrl += "firstname=" + firstname;
    requestUrl += "lastname=" + lastname;

        QNetworkReply *reply = m_networkManager.get(QNetworkRequest(QUrl(requestUrl)));
        reply->setProperty("requestType", "signUp");









    //QUrl url("http://api.barafardayebehtar.ml:8080/signup");

    // Create a query string with the parameters
    //QUrlQuery query;
    //query.addQueryItem("username", username);
    //query.addQueryItem("password", password);
    //query.addQueryItem("firstname", firstname);
    //query.addQueryItem("lastname",lastname);

    // Append the query to the URL
    //url.setQuery(query);

    // Create a network request with the URL
    //QNetworkRequest request(url);

    // Send the request and get the reply
    //QNetworkReply* reply = m_networkManager.get(request);

    // Connect the signals for the reply
    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Read the response data
            QByteArray response = reply->readAll();

            // Parse the JSON response
            QJsonDocument jsonResponse = QJsonDocument::fromJson(response);
            QJsonObject jsonObject = jsonResponse.object();

            // Get the message and code from the JSON object
            QString message = jsonObject["message"].toString();
            QString code = jsonObject["code"].toString();

            // Emit the response signal
            emit signUpResponse(message, code);
        } else {
            // Handle the error case
            emit signUpResponse(reply->errorString(), "");
            //QMessageBox::information(nullptr, reply->errorString(),reply->errorString());
        }

        // Clean up
        reply->deleteLater();
    });
}
