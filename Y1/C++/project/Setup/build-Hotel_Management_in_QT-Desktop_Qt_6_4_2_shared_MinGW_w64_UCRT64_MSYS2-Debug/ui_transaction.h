/********************************************************************************
** Form generated from reading UI file 'transaction.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSACTION_H
#define UI_TRANSACTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_transaction
{
public:
    QListWidget *lstWidget;
    QLabel *label;

    void setupUi(QDialog *transaction)
    {
        if (transaction->objectName().isEmpty())
            transaction->setObjectName("transaction");
        transaction->setWindowModality(Qt::WindowModal);
        transaction->resize(320, 240);
        lstWidget = new QListWidget(transaction);
        lstWidget->setObjectName("lstWidget");
        lstWidget->setGeometry(QRect(10, 40, 301, 111));
        label = new QLabel(transaction);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 23, 301, 20));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label->setFont(font);

        retranslateUi(transaction);

        QMetaObject::connectSlotsByName(transaction);
    } // setupUi

    void retranslateUi(QDialog *transaction)
    {
        transaction->setWindowTitle(QCoreApplication::translate("transaction", "Booking Transaction", nullptr));
        label->setText(QCoreApplication::translate("transaction", "Transaction Id         Room No         Customer Id         ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class transaction: public Ui_transaction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSACTION_H
