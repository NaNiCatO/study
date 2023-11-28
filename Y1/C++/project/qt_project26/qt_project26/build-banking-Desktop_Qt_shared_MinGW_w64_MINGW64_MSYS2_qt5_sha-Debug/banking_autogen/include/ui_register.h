/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_pass;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName("Register");
        Register->resize(564, 420);
        label = new QLabel(Register);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 201, 61));
        label->setStyleSheet(QString::fromUtf8("*{\n"
"    font-family: century gothic;\n"
"font-size:24px;\n"
"}\n"
"QFrame\n"
"{\n"
"background:    rgb(115, 215, 255);\n"
"border-radius:30px;\n"
"}"));
        label_2 = new QLabel(Register);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 190, 201, 61));
        label_2->setStyleSheet(QString::fromUtf8("*{\n"
"    font-family: century gothic;\n"
"font-size:24px;\n"
"}\n"
"QFrame\n"
"{\n"
"background:    rgb(115, 215, 255);\n"
"border-radius:30px;\n"
"}"));
        pushButton = new QPushButton(Register);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(420, 350, 111, 41));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background:    rgb(115, 215, 255);\n"
"border-radius:10px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color: white\n"
"border-radius:15px;\n"
"background:#49ebff;\n"
"}"));
        lineEdit_name = new QLineEdit(Register);
        lineEdit_name->setObjectName("lineEdit_name");
        lineEdit_name->setGeometry(QRect(20, 110, 331, 51));
        lineEdit_pass = new QLineEdit(Register);
        lineEdit_pass->setObjectName("lineEdit_pass");
        lineEdit_pass->setGeometry(QRect(20, 270, 331, 51));

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Register", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">Username</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Register", "<html><head/><body><p align=\"center\">Password</p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("Register", "confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
