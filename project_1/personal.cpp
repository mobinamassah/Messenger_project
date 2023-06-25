#include "personal.h"

personal::personal()
{
    username="";
    password="";
    firstname="";
    lastname="";
    token="";
}
personal::personal(string _username,string _password,string _firstname,string _lastname)
{
    username=_username;
    password=_password;
    firstname=_firstname;
    lastname=lastname;
    token="";
}

void personal::set_username(string _username){
   username=_username;
}
void personal::set_password(string _password){
   password=_password;
}
void personal::set_lastname(string _lastname){
   lastname=_lastname;
}
void personal::set_firstname(string _firstname){
   firstname=_firstname;
}
void personal::set_token(string _token){
   token=_token;
}

string personal:: get_username(){
   return username;
}
string personal:: get_password(){
   return password;
}
string personal:: get_lastname(){
   return lastname;
}
string personal:: get_firstname(){
   return firstname;
}
string personal:: get_token(){
   return token;
}
