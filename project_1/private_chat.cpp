#include "private_chat.h"
#include "ui_private_chat.h"

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
