#ifndef SELECTION_PAGE_H
#define SELECTION_PAGE_H

#include <QWidget>

namespace Ui {
class Selection_page;
}

class Selection_page : public QWidget
{
    Q_OBJECT

public:
    explicit Selection_page(QWidget *parent = nullptr);
    ~Selection_page();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Selection_page *ui;
};

#endif // SELECTION_PAGE_H
