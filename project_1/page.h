#ifndef PAGE_H
#define PAGE_H

#include <QDialog>
#include <QTextEdit>
#include "QVBoxLayout"
#include <QKeyEvent>
#include <QListWidget>
#include "qnetworkaccessmanager.h"
#include "user.h"

namespace Ui {
class page;
}

class page : public QDialog
{
    Q_OBJECT

public:
    explicit page(QWidget *parent = nullptr,const data_user& currentUser = data_user());
    ~page();
    void showUsers();
    QNetworkAccessManager* nemanag;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void show_chat(QString user);

    void on_listWidget_2_itemClicked(QListWidgetItem *item);

    void on_pushButton_3_clicked();

private:
    Ui::page *ui;
    data_user mCurrentUser;
    QVBoxLayout* layout;
};

#endif // PAGE_H
