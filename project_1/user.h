#ifndef USER_H
#define USER_H
#include<iostream>
#include<QString>
class data_user{
    QString username;
    QString password;
    QString token;

public:

    data_user() = default;
    data_user(QString _username , QString _password){
        username = _username;
        password = _password;
        token = nullptr;
    }
    QString getusername() const{return username;}
    QString getassword() const{return password;}
    QString gettoken() const{return token;}
    void setusername(QString _username){username = _username;}
    void setpassword(QString _password){password = _password;}
    void settoken(QString _token){token = _token;}


};

#endif // USER_H
