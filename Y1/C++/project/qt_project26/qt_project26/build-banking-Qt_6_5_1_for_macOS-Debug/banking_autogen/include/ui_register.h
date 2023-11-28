/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QPushButton *pushButton;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_name;
    QComboBox *comboBox;
    QLineEdit *lineEdit_pass;
    QDialogButtonBox *buttonBox;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName("Register");
        Register->resize(564, 420);
        Register->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background : white;\n"
"}"));
        pushButton = new QPushButton(Register);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(50, 250, 111, 41));
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
        label_5 = new QLabel(Register);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(-20, 0, 581, 381));
        label_5->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background:grey;\n"
"}"));
        label_6 = new QLabel(Register);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 20, 521, 331));
        label_6->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background:#415a77;\n"
"}"));
        label_7 = new QLabel(Register);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(160, -10, 201, 61));
        label_7->setStyleSheet(QString::fromUtf8("*{\n"
"    font-family: century gothic;\n"
"font-size:24px;\n"
"}\n"
"QFrame\n"
"{\n"
"background:    #778da9;\n"
"border-radius:30px;\n"
"}"));
        label_8 = new QLabel(Register);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(0, 50, 181, 51));
        label_8->setStyleSheet(QString::fromUtf8("*{\n"
"    font-family: century gothic;\n"
"font-size:24px;\n"
"}\n"
"QFrame\n"
"{\n"
"background:    transparent;\n"
"border-radius:30px;\n"
"}"));
        lineEdit_name = new QLineEdit(Register);
        lineEdit_name->setObjectName("lineEdit_name");
        lineEdit_name->setGeometry(QRect(20, 100, 331, 51));
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
        comboBox = new QComboBox(Register);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(30, 310, 121, 31));
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(103, 252, 255);\n"
"border-color: rgb(85, 255, 255);"));
        lineEdit_pass = new QLineEdit(Register);
        lineEdit_pass->setObjectName("lineEdit_pass");
        lineEdit_pass->setGeometry(QRect(20, 200, 331, 51));
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
        buttonBox = new QDialogButtonBox(Register);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(590, 400, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_9 = new QLabel(Register);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(0, 150, 181, 51));
        label_9->setStyleSheet(QString::fromUtf8("*{\n"
"    font-family: century gothic;\n"
"font-size:24px;\n"
"}\n"
"QFrame\n"
"{\n"
"background:    transparent;\n"
"border-radius:30px;\n"
"}"));
        label_10 = new QLabel(Register);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 260, 251, 51));
        label_10->setStyleSheet(QString::fromUtf8("*{\n"
"    font-family: century gothic;\n"
"font-size:24px;\n"
"}\n"
"QFrame\n"
"{\n"
"background:    transparent;\n"
"border-radius:30px;\n"
"}"));
        pushButton_2 = new QPushButton(Register);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(400, 300, 111, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Register", "confirm", nullptr));
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QCoreApplication::translate("Register", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt;\">Register</span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("Register", "<html><head/><body><p align=\"center\">Username:</p></body></html>", nullptr));
        lineEdit_name->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("Register", "No limit", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Register", "Limit", nullptr));

        lineEdit_pass->setInputMask(QString());
        lineEdit_pass->setText(QString());
        label_9->setText(QCoreApplication::translate("Register", "<html><head/><body><p align=\"center\">Password:</p></body></html>", nullptr));
        label_10->setText(QCoreApplication::translate("Register", "<html><head/><body><p align=\"center\">Select accout type:</p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Register", "confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
