/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit_name;
    QLabel *label_9;
    QLineEdit *lineEdit_pass;
    QLabel *label_5;
    QPushButton *pushButton;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(599, 384);
        buttonBox = new QDialogButtonBox(Login);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(620, 400, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit_name = new QLineEdit(Login);
        lineEdit_name->setObjectName("lineEdit_name");
        lineEdit_name->setGeometry(QRect(50, 100, 331, 51));
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
        label_9 = new QLabel(Login);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 150, 181, 51));
        label_9->setStyleSheet(QString::fromUtf8("*{\n"
"    font-family: century gothic;\n"
"font-size:24px;\n"
"}\n"
"QFrame\n"
"{\n"
"background:    transparent;\n"
"border-radius:30px;\n"
"}"));
        lineEdit_pass = new QLineEdit(Login);
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
        label_5 = new QLabel(Login);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 0, 591, 381));
        label_5->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background:grey;\n"
"}"));
        pushButton = new QPushButton(Login);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(420, 290, 111, 41));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background:    grey;\n"
"border-radius:10px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color: white\n"
"border-radius:15px;\n"
"background:#49ebff;\n"
"}"));
        label_8 = new QLabel(Login);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 50, 181, 51));
        label_8->setStyleSheet(QString::fromUtf8("*{\n"
"    font-family: century gothic;\n"
"font-size:24px;\n"
"}\n"
"QFrame\n"
"{\n"
"background:    transparent;\n"
"border-radius:30px;\n"
"}"));
        label_6 = new QLabel(Login);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 20, 521, 331));
        label_6->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background:#415a77;\n"
"}"));
        label_7 = new QLabel(Login);
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
        lineEdit_name->raise();
        label_9->raise();
        lineEdit_pass->raise();
        pushButton->raise();
        label_8->raise();
        label_7->raise();

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Dialog", nullptr));
        lineEdit_name->setText(QString());
        label_9->setText(QCoreApplication::translate("Login", "<html><head/><body><p align=\"center\">Password:</p></body></html>", nullptr));
        lineEdit_pass->setInputMask(QString());
        lineEdit_pass->setText(QString());
        label_5->setText(QString());
        pushButton->setText(QCoreApplication::translate("Login", "confirm", nullptr));
        label_8->setText(QCoreApplication::translate("Login", "<html><head/><body><p align=\"center\">Username:</p></body></html>", nullptr));
        label_6->setText(QString());
        label_7->setText(QCoreApplication::translate("Login", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt;\">Login</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
