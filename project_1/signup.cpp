#include "signup.h"
#include "ui_signup.h"
#include "mainwindow.h"
#include <QMessageBox>
#include "qcryptographichash.h"

signup::signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}
