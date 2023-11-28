/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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
        label->setGeometry(QRect(220, 100, 341, 151));
        label->setStyleSheet(QString::fromUtf8("*{\n"
"    font-family: century gothic;\n"
"font-size:24px;\n"
"}\n"
"QFrame\n"
"{\n"
"background:    rgb(115, 215, 255);\n"
"border-radius:60px;\n"
"}"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(110, 310, 121, 121));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background:    rgb(115, 215, 255);\n"
"border-radius:60px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color: white\n"
"border-radius:15px;\n"
"background:#49ebff;\n"
"}"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(570, 310, 121, 121));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background:    rgb(115, 215, 255);\n"
"border-radius:60px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color: white\n"
"border-radius:15px;\n"
"background:#49ebff;\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
