#include "selection_page.h"
#include "menu.h"
#include "ui_selection_page.h"
#include <private_chat.h>
Selection_page::Selection_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Selection_page)
{
    ui->setupUi(this);
}

Selection_page::~Selection_page()
{
    delete ui;
}

void Selection_page::on_pushButton_clicked()
{
    private_chat *pc=new private_chat();
    pc->setWindowFlags(Qt::CustomizeWindowHint |Qt::FramelessWindowHint);
    pc->show();
    this->close();
}




void Selection_page::on_pushButton_4_clicked()
{
    menu *a=new menu();
    a->setWindowFlags(Qt::CustomizeWindowHint |Qt::FramelessWindowHint);
    a->show();
    this->close();
}

