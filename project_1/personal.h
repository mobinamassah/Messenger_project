#ifndef PERSONAL_H
#define PERSONAL_H
#include <QMainWindow>
#include<iostream>
#include<map>
#include<windows.h>
#include<algorithm>
#include <QMainWindow>
using namespace std;


class personal
{
private:
        QString username;
        QString password;
        QString token;
        QString lastname;
        QString firstname;
public:
        QString get_username();
        QString get_password();
        QString get_lastname();
        QString get_firstname();
        QString get_token();
        void set_username(QString _username);
        void set_password(QString _password);
        void set_lastname(QString _lastname);
        void set_firstname(QString _firstname);
        void set_token(QString _token);
        personal();
        personal(QString _username,QString _password,QString _firstname,QString _lastname);
};

#endif // PERSONAL_H
