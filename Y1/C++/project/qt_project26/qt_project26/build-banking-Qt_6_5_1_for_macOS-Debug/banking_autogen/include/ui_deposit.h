/********************************************************************************
** Form generated from reading UI file 'deposit.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSIT_H
#define UI_DEPOSIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Deposit
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_3;
    QLineEdit *lineEdit_name;

    void setupUi(QDialog *Deposit)
    {
        if (Deposit->objectName().isEmpty())
            Deposit->setObjectName("Deposit");
        Deposit->resize(580, 376);
        buttonBox = new QDialogButtonBox(Deposit);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(200, 310, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Deposit);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 581, 381));
        label->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background:grey;\n"
"}"));
        label_5 = new QLabel(Deposit);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 20, 521, 331));
        label_5->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background:#415a77;\n"
"}"));
        label_6 = new QLabel(Deposit);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(180, -10, 201, 61));
        label_6->setStyleSheet(QString::fromUtf8("*{\n"
"    font-family: century gothic;\n"
"font-size:24px;\n"
"}\n"
"QFrame\n"
"{\n"
"background:    #778da9;\n"
"border-radius:30px;\n"
"}"));
        label_3 = new QLabel(Deposit);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 110, 181, 51));
        label_3->setStyleSheet(QString::fromUtf8("*{\n"
"    font-family: century gothic;\n"
"font-size:24px;\n"
"}\n"
"QFrame\n"
"{\n"
"background:    transparent;\n"
"border-radius:30px;\n"
"}"));
        lineEdit_name = new QLineEdit(Deposit);
        lineEdit_name->setObjectName("lineEdit_name");
        lineEdit_name->setGeometry(QRect(40, 160, 331, 51));
        lineEdit_name->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"background-color: rgb(254, 254, 254);\n"
"border : 2px solid rgb(37, 39,48);\n"
"border-radius: 20px;\n"
"color:#FFF;\n"
"padding-left: 20px;\n"
"pdffing-right: 20px;\n"
"background-color:grey;\n"
"}\n"
"QLineEdit:hover{\n"
"border : 2px solid rgb(48,50,62);\n"
"}\n"
"QLineEdit:focus{\n"
"border : 2px solid rgb(85,170,255);\n"
"background-color: rgb :rgb(43,45,56);\n"
"}\n"
"\n"
"\n"
"\n"
""));
        label->raise();
        label_5->raise();
        label_6->raise();
        label_3->raise();
        lineEdit_name->raise();
        buttonBox->raise();

        retranslateUi(Deposit);

        QMetaObject::connectSlotsByName(Deposit);
    } // setupUi

    void retranslateUi(QDialog *Deposit)
    {
        Deposit->setWindowTitle(QCoreApplication::translate("Deposit", "Dialog", nullptr));
        label->setText(QString());
        label_5->setText(QString());
        label_6->setText(QCoreApplication::translate("Deposit", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt;\">Deposit</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Deposit", "<html><head/><body><p align=\"center\">Deposit Amount :</p></body></html>", nullptr));
        lineEdit_name->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Deposit: public Ui_Deposit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSIT_H
