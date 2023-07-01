#include "file_function.h"
#include "mainwindow.h"
#include <QFile>

void file_write(QString fname,personal p){
    QFile file(fname);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
            QTextStream out(&file);
            out << p.get_username() << "/" << p.get_password() << "/" <<p.get_token();
            out << "\n";
        }
        file.close();
}
void file_read(QString fname){

        QFile file(fname);
           if (file.open(QIODevice::ReadOnly | QIODevice::Text))
           {
            QTextStream in(&file);
            while(!in.atEnd()){
                QString line=in.readLine();
                QStringList fields=line.split("/");
                QString username=fields[0];
                QString password=fields[1];
                QString token=fields[2];
                //QString firstname=fields[2];
                //QString lastname=fields[3];

                personal *p=new personal(username,password,token);
                //p.get_username() = username;
                //p.get_password() = password;
                //p.get_firstname() = firstname;
                //p.get_lastname() = lastname;
                //information.insert(make_pair(username, p));
                information.push_back(p);
            }
            file.close();
            }

}
