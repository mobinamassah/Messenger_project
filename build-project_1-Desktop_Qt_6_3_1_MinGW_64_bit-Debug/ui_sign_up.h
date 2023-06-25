/********************************************************************************
** Form generated from reading UI file 'sign_up.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGN_UP_H
#define UI_SIGN_UP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_sign_up
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;

    void setupUi(QDialog *sign_up)
    {
        if (sign_up->objectName().isEmpty())
            sign_up->setObjectName(QString::fromUtf8("sign_up"));
        sign_up->resize(400, 300);
        buttonBox = new QDialogButtonBox(sign_up);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(sign_up);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(18, 20, 361, 271));
        lineEdit = new QLineEdit(sign_up);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(130, 40, 113, 22));
        lineEdit_2 = new QLineEdit(sign_up);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(130, 90, 113, 22));
        lineEdit_3 = new QLineEdit(sign_up);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(130, 130, 113, 22));
        lineEdit_4 = new QLineEdit(sign_up);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(140, 180, 113, 22));

        retranslateUi(sign_up);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, sign_up, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, sign_up, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(sign_up);
    } // setupUi

    void retranslateUi(QDialog *sign_up)
    {
        sign_up->setWindowTitle(QCoreApplication::translate("sign_up", "Dialog", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class sign_up: public Ui_sign_up {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGN_UP_H
