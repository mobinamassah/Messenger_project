#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signup.h"
#include "vector"
class data {
private:
    QString username;
    QString password;
    QString lastname;
    QString firstname;
public:
    QString get_username(){
        return username;
    }
    QString get_password(){
        return password;
    }
    QString get_lastname(){
        return lastname;
    }
    QString get_firstname(){
        return firstname;
    }
    void set_username(QString _username){
        username=_username;
    }
    void set_password(QString _password){
        password=_password;
    }
     void set_lastname(QString _lastname){
            lastname=_lastname;
     }
     void set_firstname(QString _firstname){
            firstname=_firstname;
     }


};
QVector<data>T;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    signup *s=new signup();
    s->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    s->show();
    hide();

}

