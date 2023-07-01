#ifndef PRIVATE_CHAT_H
#define PRIVATE_CHAT_H

#include <QWidget>

namespace Ui {
class private_chat;
}

class private_chat : public QWidget
{
    Q_OBJECT

public:
    explicit private_chat(QWidget *parent = nullptr);
    ~private_chat();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::private_chat *ui;
};

#endif // PRIVATE_CHAT_H
