#include "data.h"
#include <QString>
using namespace std;
data::data()
{
 username="";
 password="";
 firstname="";
 lastname="";
}
void data::set_username(QString _username){
    username=_username;
}
void data::set_password(QString _password){
    password=_password;
}
void data::set_lastname(QString _lastname){
    lastname=_lastname;
}
void data::set_firstname(QString _firstname){
    firstname=_firstname;
}

QString data:: get_username(){
    return username;
}
QString data:: get_password(){
    return password;
}
QString data:: get_lastname(){
    return lastname;
}
QString data:: get_firstname(){
    return firstname;
}
