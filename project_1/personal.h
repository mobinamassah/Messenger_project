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
        string username;
        string password;
        string token;
        string lastname;
        string firstname;
public:
        string get_username();
        string get_password();
        string get_lastname();
        string get_firstname();
        string get_token();
        void set_username(string _username);
        void set_password(string _password);
        void set_lastname(string _lastname);
        void set_firstname(string _firstname);
        void set_token(string _token);
        personal();
        personal(string _username,string _password,string _firstname,string _lastname);
};

#endif // PERSONAL_H
