#ifndef DATA_H
#define DATA_H
#include <QString>

class data
{
private:
        QString username;
        QString password;
        QString lastname;
        QString firstname;
public:
        data();
        QString get_username();
        QString get_password();
        QString get_lastname();
        QString get_firstname();
        void set_username(QString _username);
        void set_password(QString _password);
        void set_lastname(QString _lastname);
        void set_firstname(QString _firstname);


};
#endif // DATA_H
