#include "page.h"
#include "ui_page.h"
#include <QUrlQuery>
#include <QtNetwork>
#include <QKeyEvent>
#include <QWidget>
#include <QScrollArea>
#include <QVector>
#include <QTimer>
#include <QThread>

struct messag {
    QString src;
    QString dst;
    QString body;
    QString date;
    QDateTime dateTime;
    QString dateString;
};
QVector<QString> getuserlist(QString token);
QVector<QString> getuserlist(QString token){
    QString url1= "http://api.barafardayebehtar.ml:8080/getuserlist?token=";
    url1=url1+token;
    QUrl url(url1);
    QNetworkAccessManager manager;

    QNetworkRequest request;
    request.setUrl(url);
    QNetworkReply* reply = manager.get(request);


    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QString response;
    if (reply->error() == QNetworkReply::NoError) {

        QByteArray responseData = reply->readAll();
        response = QString(responseData);
    } else {

        qDebug() << "Error:" << reply->errorString();
    }


    reply->deleteLater();

    QString temp=response;

    QString serverResponse = response;

    QVector<QString> names;


    QJsonDocument jsonDoc = QJsonDocument::fromJson(serverResponse.toUtf8());
    if (!jsonDoc.isNull() && jsonDoc.isObject()) {
        QJsonObject jsonObj = jsonDoc.object();


        QStringList blockKeys = jsonObj.keys().filter("block ");
        for (const QString& blockKey : blockKeys) {
            QJsonObject blockObj = jsonObj[blockKey].toObject();
            if (blockObj.contains("src")) {
                names.append(blockObj["src"].toString());
            }
        }
    }

    return names;

}

QString logout(QString user,QString pass);
QString response_code(QString Server_Response){

    QString searchString1 = "\"204\"";
    QString searchString2 = "\"404\"";
    QString searchString3 = "\"401\"";
    QString searchString4 = "\"200\"";
    if(Server_Response.contains(searchString1)){
        return "204";
    }
    if(Server_Response.contains(searchString2)){
        return "404";
    }
    if(Server_Response.contains(searchString3)){
        return "401";
    }
    if(Server_Response.contains(searchString4)){
        return "200";
    }
    else{
        return "Error";
    }

}

QString extractSubstring_for_extracting_the_chat_info(const QString& original, QString& first, QString& second) {
    int firstPos = original.indexOf(first);
    if (firstPos == -1) {

        return QString();
    }

    int secondPos = original.indexOf(second, firstPos + first.length());
    if (secondPos == -1) {

        return QString();
    }


    first = original.mid(firstPos + first.length(), secondPos - firstPos - first.length());


    QString remaining = original.mid(secondPos + second.length());

    return remaining;
}
bool sortMessageBlocks(const messag& block1, const messag& block2) {
    return block1.dateTime < block2.dateTime;
}

QString sendmessagegroup_chat_to_server(QString token,QString dst , QString body) {
    QString url1= "http://api.barafardayebehtar.ml:8080/sendmessagegroup?token=";
    QString url2= "&dst=";
    QString url3= "&body=";
    url1=url1+token+url2+dst+url3+body;
    QUrl url(url1);

    QNetworkAccessManager manager;


    QNetworkRequest request;
    request.setUrl(url);


    QNetworkReply* reply = manager.get(request);


    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QString response;
    if (reply->error() == QNetworkReply::NoError) {

        QByteArray responseData = reply->readAll();
        response = QString(responseData);
    } else {

        qDebug() << "Error:" << reply->errorString();
    }


    reply->deleteLater();
    QString response_code_login_server = response_code(response);

    return response_code_login_server;

}
QString sendmessageuser_chat_to_server(QString token,QString dst , QString body) {
    QString url1= "http://api.barafardayebehtar.ml:8080/sendmessageuser?token=";
    QString url2= "&dst=";
    QString url3= "&body=";
    url1=url1+token+url2+dst+url3+body;
    QUrl url(url1);

    QNetworkAccessManager manager;


    QNetworkRequest request;
    request.setUrl(url);


    QNetworkReply* reply = manager.get(request);


    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QString response;
    if (reply->error() == QNetworkReply::NoError) {

        QByteArray responseData = reply->readAll();
        response = QString(responseData);
    } else {

        qDebug() << "Error:" << reply->errorString();
    }


    reply->deleteLater();
    QString response_code_login_server = response_code(response);

    return response_code_login_server;
}

QString sendmessagechannel_chat_to_server(QString token,QString dst , QString body) {
    QString url1= "http://api.barafardayebehtar.ml:8080/sendmessagechannel?token=";
    QString url2= "&dst=";
    QString url3= "&body=";
    url1=url1+token+url2+dst+url3+body;
    QUrl url(url1);

    QNetworkAccessManager manager;


    QNetworkRequest request;
    request.setUrl(url);


    QNetworkReply* reply = manager.get(request);


    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QString response;
    if (reply->error() == QNetworkReply::NoError) {

        QByteArray responseData = reply->readAll();
        response = QString(responseData);
    } else {

        qDebug() << "Error:" << reply->errorString();
    }


    reply->deleteLater();
    QString response_code_login_server = response_code(response);

    return response_code_login_server;
}

QString findSubstringAndReturnRest(const QString& originalString, const QString& substring)
{
    int index = originalString.indexOf(substring);

    if (index != -1) {

        return originalString.mid(index + substring.length());
    }


    return "";
}

QString getStringBetweenLastTwoStrings(const QString& first, const QString& second, const QString& third)
{
    int secondIndex = first.lastIndexOf(second);
    int thirdIndex = first.lastIndexOf(third);

    if (secondIndex == -1 || thirdIndex == -1 || secondIndex >= thirdIndex)
    {
        return QString();
    }

    int startIndex = secondIndex + second.length();
    int length = thirdIndex - startIndex;
    return first.mid(startIndex, length);
}

QVector<messag> getuserchats_server_to_chat_display(QString token,QString dst) {
    QString url1= "http://api.barafardayebehtar.ml:8080/getuserchats?token=";
    QString url2= "&dst=";

    url1=url1+token+url2+dst;
    QUrl url(url1);


    QNetworkAccessManager manager;


    QNetworkRequest request;
    request.setUrl(url);


    QNetworkReply* reply = manager.get(request);


    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QString response;
    if (reply->error() == QNetworkReply::NoError) {

        QByteArray responseData = reply->readAll();
        response = QString(responseData);
    } else {

        qDebug() << "Error:" << reply->errorString();
    }


    reply->deleteLater();


    QVector<messag> messageBlocks;


    QJsonDocument jsonResponse = QJsonDocument::fromJson(response.toUtf8());

    if (!jsonResponse.isNull()) {
        if (jsonResponse.isObject()) {
            QJsonObject jsonObject = jsonResponse.object();


            QString message = jsonObject["message"].toString();
            QString code = jsonObject["code"].toString();

            qDebug() << "Message: " << message;
            qDebug() << "Code: " << code;


            QJsonObject::iterator it;
            for (it = jsonObject.begin(); it != jsonObject.end(); ++it) {
                QString key = it.key();
                if (key.startsWith("block")) {
                    QJsonObject blockObject = it.value().toObject();


                    QString body = blockObject["body"].toString();
                    QString src = blockObject["src"].toString();
                    QString dst = blockObject["dst"].toString();
                    QString date = blockObject["date"].toString();


                    messag clock;
                    clock.src = src;
                    clock.dst = dst;
                    clock.body = body;
                    clock.date = date;

                    messageBlocks.append(clock);
                }
            }
        } else {
            qDebug() << "Invalid JSON response: Not an object";
        }
    } else {
        qDebug() << "Invalid JSON response: Failed to parse";
    }

    return messageBlocks;
}

QString signup(QString user,QString pass) {

    QString url1 = "http://api.barafardayebehtar.ml:8080/signup?username=";
        QString url2 = "&password=";

        url1 = url1 + user + url2 + pass;
        QUrl url(url1);

        QNetworkAccessManager manager;


        QNetworkRequest request;
        request.setUrl(url);


        QNetworkReply* reply = manager.get(request);


        QEventLoop loop;
        QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();

        QString response;
        if (reply->error() == QNetworkReply::NoError) {

            QByteArray responseData = reply->readAll();
            response = QString(responseData);
        }
        else {

            qDebug() << "Error:" << reply->errorString();
        }


        reply->deleteLater();

        return response_code(response);
}


QString CurrentUsername;
QString CurrentPassword;
QString UserToken;

void page::showUsers()
{
    QVector<QString> user = getuserlist(UserToken);
    for(int i = user.size()-1 ; i >= 0; i--){
        ui->listWidget_2->addItem(user[i]);
    }

}
page::page(QWidget *parent,const data_user& currentUser) :
    QDialog(parent),
    ui(new Ui::page),
     mCurrentUser(currentUser)
{
    ui->setupUi(this);

    QString username = currentUser.getusername();
    QString password = currentUser.getassword();
    QString token = currentUser.gettoken();
    CurrentUsername=username;
    CurrentPassword = password;
    UserToken = token;

    ui->label_3->setText(username);


}



page::~page()
{
    delete ui;
}
void page::show_users_chat(QString user)
{
    QVector<messag> chats = getuserchats_server_to_chat_display(UserToken, user);
    ui->listWidget->clear();
    for (int i = 0; i < chats.size(); i++) {
        // user name
        if (chats.at(i).src == ui->label->text()) {
            QString text = chats.at(i).body;
            QString name = chats.at(i).src;
            QString date = chats.at(i).dateString;
            QString formattedText;

            int charCount = 0;
            const int maxCharsPerLine = 50;
            const int marginForLineBreak = 30;

            int labelHeight = 40;
            QString message = name + ":\n" + text + "\n" + date;

            for (const QChar& character : message) {
                formattedText.append(character);
                charCount++;

                if (charCount == maxCharsPerLine) {
                    formattedText.append('\n');
                    charCount = 0;
                    labelHeight += marginForLineBreak;
                }
            }

            QLabel* label = new QLabel(formattedText);
            label->setStyleSheet("QLabel { color: white; background-color: rgb(0, 170, 255); font: 12pt 'Segoe UI'; border-radius: 5px; margin-right: 400px; }"); // Set the label's style with right margin
            label->setAlignment(Qt::AlignLeft);

            labelHeight += (text.count('\n') * marginForLineBreak);

            QListWidgetItem* newItem = new QListWidgetItem();
            newItem->setSizeHint(QSize(0, labelHeight + 25));
            ui->listWidget->addItem(newItem);
            ui->listWidget->setItemWidget(newItem, label);
            ui->listWidget->setSpacing(10);
            ui->listWidget->scrollToBottom();

        }
        else if (chats.at(i).src == ui->label_2->text()) {
            QString text = chats.at(i).body;
            QString name = chats.at(i).src;
            QString date = chats.at(i).dateString;
            QString formattedText;

            int charCount = 0;
            const int maxCharsPerLine = 50;
            const int marginForLineBreak = 30;

            int labelHeight = 40;

            QString message = name + ":\n" + text + "\n" + date;

            for (const QChar& character : message) {
                formattedText.append(character);
                charCount++;

                if (charCount == maxCharsPerLine) {
                    formattedText.append('\n');
                    charCount = 0;
                    labelHeight += marginForLineBreak;
                }
            }

            QLabel* label = new QLabel(formattedText);
            label->setStyleSheet("QLabel { color: white; background-color: rgb(0, 85, 127); font: 12pt 'Segoe UI'; border-radius: 5px; margin-right: 400px; }"); // Set the label's style with right margin
            label->setAlignment(Qt::AlignLeft);

            labelHeight += (text.count('\n') * marginForLineBreak);

            QListWidgetItem* newItem = new QListWidgetItem();
            newItem->setSizeHint(QSize(0, labelHeight + 25));
            ui->listWidget->addItem(newItem);
            ui->listWidget->setItemWidget(newItem, label);
            ui->listWidget->setSpacing(10);
            ui->listWidget->scrollToBottom();
        }
    }
}




void page::on_pushButton_clicked()
{
close();
}



void page::on_pushButton_2_clicked()
{
    QString name = ui->label_2->text();
        QString text = ui->textEdit->toPlainText();


        int currentIndex = ui->tabWidget->currentIndex();

        if (text.isEmpty()) {
            return;
        }

        if (currentIndex == 0) {
            sendmessageuser_chat_to_server(UserToken, name, text);
            ui->textEdit->clear();
            show_users_chat(name);

        }

}
void page::on_listWidget_2_itemClicked(QListWidgetItem *item)
{
        QString name = item->text();
        ui->label_2->setText(name);
        show_users_chat(name);
}





void page::on_toolButton_clicked()
{
    QString username = ui->lineEdit->text();
        ui->lineEdit->clear();
        sendmessageuser_chat_to_server(UserToken, username, "hi");

}

