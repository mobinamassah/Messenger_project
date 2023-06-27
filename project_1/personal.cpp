#include "personal.h"

personal::personal()
{
    username="";
    password="";
    firstname="";
    lastname="";
    token="";
}
personal::personal(QString _username, QString _password, QString _firstname, QString _lastname)
{
    username=_username;
    password=_password;
    firstname=_firstname;
    lastname=lastname;
    token="";
}

void personal::set_username(QString _username){
   username=_username;
}
void personal::set_password(QString _password){
   password=_password;
}
void personal::set_lastname(QString _lastname){
   lastname=_lastname;
}
void personal::set_firstname(QString _firstname){
   firstname=_firstname;
}
void personal::set_token(QString _token){
   token=_token;
}

QString personal:: get_username(){
   return username;
}
QString personal:: get_password(){
   return password;
}
QString personal:: get_lastname(){
   return lastname;
}
QString personal:: get_firstname(){
   return firstname;
}
QString personal:: get_token(){
   return token;
}
