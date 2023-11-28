/********************************************************************************
** Form generated from reading UI file 'user_login.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_LOGIN_H
#define UI_USER_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_User_login
{
public:
    QLabel *label;
    QPushButton *pushButton_2;
    QLabel *label_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_1;

    void setupUi(QDialog *User_login)
    {
        if (User_login->objectName().isEmpty())
            User_login->setObjectName("User_login");
        User_login->resize(642, 466);
        label = new QLabel(User_login);
        label->setObjectName("label");
        label->setGeometry(QRect(150, -20, 331, 121));
        label->setStyleSheet(QString::fromUtf8("*{\n"
"    font-family: century gothic;\n"
"font-size:24px;\n"
"}\n"
"QFrame\n"
"{\n"
"background:    #778da9;\n"
"border-radius:60px;\n"
"}"));
        pushButton_2 = new QPushButton(User_login);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(130, 250, 341, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("*{\n"
"    font-family: century gothic;\n"
"font-size:36px;\n"
"}\n"
"\n"
"\n"
"QPushButton {\n"
"    background: #061f57;\n"
"    border-radius: 60px;\n"
"}\n"
"\n"
"QToolButton {\n"
"    background: #red;\n"
"    border-radius: 60px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    color: white;\n"
"    border-radius: 15px;\n"
"    background: #1b263b;\n"
"    transition: background 0.3s, color 0.3s;\n"
"}\n"
""));
        label_5 = new QLabel(User_login);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(-20, -20, 681, 501));
        label_5->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background:grey;\n"
"}"));
        pushButton_3 = new QPushButton(User_login);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(120, 340, 321, 91));
        pushButton_3->setStyleSheet(QString::fromUtf8("*{\n"
"    font-family: century gothic;\n"
"font-size:36px;\n"
"}\n"
"\n"
"\n"
"QPushButton {\n"
"    background: #061f57;\n"
"    border-radius: 60px;\n"
"}\n"
"\n"
"QToolButton {\n"
"    background: #red;\n"
"    border-radius: 60px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    color: white;\n"
"    border-radius: 15px;\n"
"    background: #1b263b;\n"
"    transition: background 0.3s, color 0.3s;\n"
"}\n"
""));
        pushButton_1 = new QPushButton(User_login);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setGeometry(QRect(160, 130, 251, 81));
        label_5->raise();
        label->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_1->raise();

        retranslateUi(User_login);

        QMetaObject::connectSlotsByName(User_login);
    } // setupUi

    void retranslateUi(QDialog *User_login)
    {
        User_login->setWindowTitle(QCoreApplication::translate("User_login", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("User_login", "<html><head/><body><p align=\"center\">Mode</p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("User_login", "Withdraw", nullptr));
        label_5->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("User_login", "Transaction", nullptr));
        pushButton_1->setText(QCoreApplication::translate("User_login", "deposit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class User_login: public Ui_User_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_LOGIN_H
