/********************************************************************************
** Form generated from reading UI file 'checkoutdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKOUTDIALOG_H
#define UI_CHECKOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CheckOutDialog
{
public:
    QComboBox *cmbRoomList;
    QLabel *label;
    QPushButton *btnCheckout;
    QPushButton *btnCancel;

    void setupUi(QDialog *CheckOutDialog)
    {
        if (CheckOutDialog->objectName().isEmpty())
            CheckOutDialog->setObjectName("CheckOutDialog");
        CheckOutDialog->setWindowModality(Qt::WindowModal);
        CheckOutDialog->resize(320, 128);
        cmbRoomList = new QComboBox(CheckOutDialog);
        cmbRoomList->setObjectName("cmbRoomList");
        cmbRoomList->setGeometry(QRect(160, 30, 69, 22));
        QFont font;
        font.setPointSize(12);
        cmbRoomList->setFont(font);
        label = new QLabel(CheckOutDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 30, 91, 21));
        label->setFont(font);
        btnCheckout = new QPushButton(CheckOutDialog);
        btnCheckout->setObjectName("btnCheckout");
        btnCheckout->setGeometry(QRect(80, 80, 70, 25));
        QFont font1;
        font1.setPointSize(10);
        btnCheckout->setFont(font1);
        btnCancel = new QPushButton(CheckOutDialog);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(160, 80, 70, 25));
        btnCancel->setFont(font1);

        retranslateUi(CheckOutDialog);

        QMetaObject::connectSlotsByName(CheckOutDialog);
    } // setupUi

    void retranslateUi(QDialog *CheckOutDialog)
    {
        CheckOutDialog->setWindowTitle(QCoreApplication::translate("CheckOutDialog", "Check Out", nullptr));
        label->setText(QCoreApplication::translate("CheckOutDialog", "Select Room", nullptr));
        btnCheckout->setText(QCoreApplication::translate("CheckOutDialog", "Check Out", nullptr));
        btnCancel->setText(QCoreApplication::translate("CheckOutDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CheckOutDialog: public Ui_CheckOutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKOUTDIALOG_H
