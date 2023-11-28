/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QDialogButtonBox *buttonBox;
    QLabel *label_5;
    QLabel *label_6;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 0, 331, 121));
        label->setStyleSheet(QString::fromUtf8("*{\n"
"    font-family: century gothic;\n"
"font-size:24px;\n"
"}\n"
"QFrame\n"
"{\n"
"background:    #778da9;\n"
"border-radius:60px;\n"
"}"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(120, 150, 431, 121));
        pushButton->setStyleSheet(QString::fromUtf8("*{\n"
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
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(120, 290, 451, 121));
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
        buttonBox = new QDialogButtonBox(centralwidget);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(590, 370, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(-10, 0, 681, 501));
        label_5->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background:grey;\n"
"}"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 70, 641, 371));
        label_6->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background:#415a77;\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        label_5->raise();
        label_6->raise();
        label->raise();
        pushButton->raise();
        pushButton_2->raise();
        buttonBox->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:48pt;\">Banking</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_5->setText(QString());
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
