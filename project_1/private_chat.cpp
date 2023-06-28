#include "private_chat.h"
#include "ui_private_chat.h"
#include "selection_page.h"

private_chat::private_chat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::private_chat)
{
    ui->setupUi(this);
}

private_chat::~private_chat()
{
    delete ui;
}

void private_chat::on_pushButton_2_clicked()
{
        Selection_page *p=new Selection_page();
        p->setWindowFlags(Qt::CustomizeWindowHint |Qt::FramelessWindowHint);
        p->show();
        this->close();

}

