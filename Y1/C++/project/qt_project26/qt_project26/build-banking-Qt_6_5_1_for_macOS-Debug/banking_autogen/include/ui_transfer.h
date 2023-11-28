/********************************************************************************
** Form generated from reading UI file 'transfer.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFER_H
#define UI_TRANSFER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Transfer
{
public:
    QDialogButtonBox *buttonBox;
    QDialogButtonBox *buttonBox_2;
    QLineEdit *lineEdit_name_2;
    QLabel *label_9;
    QLineEdit *lineEdit_pass;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QDialog *Transfer)
    {
        if (Transfer->objectName().isEmpty())
            Transfer->setObjectName("Transfer");
        Transfer->resize(597, 371);
        buttonBox = new QDialogButtonBox(Transfer);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(210, 320, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox_2 = new QDialogButtonBox(Transfer);
        buttonBox_2->setObjectName("buttonBox_2");
        buttonBox_2->setGeometry(QRect(620, 400, 341, 32));
        buttonBox_2->setOrientation(Qt::Horizontal);
        buttonBox_2->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit_name_2 = new QLineEdit(Transfer);
        lineEdit_name_2->setObjectName("lineEdit_name_2");
        lineEdit_name_2->setGeometry(QRect(50, 100, 331, 51));
        lineEdit_name_2->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
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
        label_9 = new QLabel(Transfer);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 150, 181, 51));
        label_9->setStyleSheet(QString::fromUtf8("*{\n"
"    font-family: century gothic;\n"
"font-size:24px;\n"
"}\n"
"QFrame\n"
"{\n"
"background:    transparent;\n"
"border-radius:30px;\n"
"}"));
        lineEdit_pass = new QLineEdit(Transfer);
        lineEdit_pass->setObjectName("lineEdit_pass");
        lineEdit_pass->setGeometry(QRect(50, 200, 331, 51));
        lineEdit_pass->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
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
        lineEdit_pass->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        label_5 = new QLabel(Transfer);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(-10, 0, 601, 381));
        label_5->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background:grey;\n"
"}"));
        label_8 = new QLabel(Transfer);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(30, 50, 181, 51));
        label_8->setStyleSheet(QString::fromUtf8("*{\n"
"    font-family: century gothic;\n"
"font-size:24px;\n"
"}\n"
"QFrame\n"
"{\n"
"background:    transparent;\n"
"border-radius:30px;\n"
"}"));
        label_6 = new QLabel(Transfer);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 20, 531, 331));
        label_6->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background:#415a77;\n"
"}"));
        label_7 = new QLabel(Transfer);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(190, -10, 201, 61));
        label_7->setStyleSheet(QString::fromUtf8("*{\n"
"    font-family: century gothic;\n"
"font-size:24px;\n"
"}\n"
"QFrame\n"
"{\n"
"background:    #778da9;\n"
"border-radius:30px;\n"
"}"));
        label_5->raise();
        label_6->raise();
        buttonBox->raise();
        buttonBox_2->raise();
        lineEdit_name_2->raise();
        label_9->raise();
        lineEdit_pass->raise();
        label_8->raise();
        label_7->raise();

        retranslateUi(Transfer);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Transfer, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Transfer, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Transfer);
    } // setupUi

    void retranslateUi(QDialog *Transfer)
    {
        Transfer->setWindowTitle(QCoreApplication::translate("Transfer", "Dialog", nullptr));
        lineEdit_name_2->setText(QString());
        label_9->setText(QCoreApplication::translate("Transfer", "<html><head/><body><p align=\"center\">Amount: </p></body></html>", nullptr));
        lineEdit_pass->setInputMask(QString());
        lineEdit_pass->setText(QString());
        label_5->setText(QString());
        label_8->setText(QCoreApplication::translate("Transfer", "<html><head/><body><p align=\"center\">Username:</p></body></html>", nullptr));
        label_6->setText(QString());
        label_7->setText(QCoreApplication::translate("Transfer", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt;\">Transaction</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Transfer: public Ui_Transfer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFER_H
