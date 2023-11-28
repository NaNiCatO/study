/********************************************************************************
** Form generated from reading UI file 'bookroomdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKROOMDIALOG_H
#define UI_BOOKROOMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_BookRoomDialog
{
public:
    QLabel *label;
    QComboBox *cmbRoomList;
    QLineEdit *txtName;
    QLineEdit *txtContactNumber;
    QTextEdit *txtAddress;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *txtIdProof;
    QPushButton *btnSubmit;
    QPushButton *btnCancel;

    void setupUi(QDialog *BookRoomDialog)
    {
        if (BookRoomDialog->objectName().isEmpty())
            BookRoomDialog->setObjectName("BookRoomDialog");
        BookRoomDialog->setWindowModality(Qt::WindowModal);
        BookRoomDialog->resize(320, 240);
        label = new QLabel(BookRoomDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 91, 21));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        cmbRoomList = new QComboBox(BookRoomDialog);
        cmbRoomList->setObjectName("cmbRoomList");
        cmbRoomList->setGeometry(QRect(110, 10, 141, 22));
        cmbRoomList->setFont(font);
        txtName = new QLineEdit(BookRoomDialog);
        txtName->setObjectName("txtName");
        txtName->setGeometry(QRect(110, 40, 141, 21));
        txtContactNumber = new QLineEdit(BookRoomDialog);
        txtContactNumber->setObjectName("txtContactNumber");
        txtContactNumber->setGeometry(QRect(110, 70, 141, 20));
        txtAddress = new QTextEdit(BookRoomDialog);
        txtAddress->setObjectName("txtAddress");
        txtAddress->setGeometry(QRect(110, 130, 141, 71));
        label_2 = new QLabel(BookRoomDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 40, 91, 21));
        label_2->setFont(font);
        label_3 = new QLabel(BookRoomDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 70, 91, 21));
        label_3->setFont(font);
        label_4 = new QLabel(BookRoomDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 130, 91, 21));
        label_4->setFont(font);
        label_5 = new QLabel(BookRoomDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 100, 91, 21));
        label_5->setFont(font);
        txtIdProof = new QLineEdit(BookRoomDialog);
        txtIdProof->setObjectName("txtIdProof");
        txtIdProof->setGeometry(QRect(110, 100, 141, 20));
        btnSubmit = new QPushButton(BookRoomDialog);
        btnSubmit->setObjectName("btnSubmit");
        btnSubmit->setGeometry(QRect(110, 210, 61, 23));
        QFont font1;
        font1.setPointSize(10);
        btnSubmit->setFont(font1);
        btnCancel = new QPushButton(BookRoomDialog);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(189, 210, 61, 23));
        btnCancel->setFont(font1);

        retranslateUi(BookRoomDialog);

        QMetaObject::connectSlotsByName(BookRoomDialog);
    } // setupUi

    void retranslateUi(QDialog *BookRoomDialog)
    {
        BookRoomDialog->setWindowTitle(QCoreApplication::translate("BookRoomDialog", "Booka a Room", nullptr));
        label->setText(QCoreApplication::translate("BookRoomDialog", "Select Room", nullptr));
        label_2->setText(QCoreApplication::translate("BookRoomDialog", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("BookRoomDialog", "Contact No", nullptr));
        label_4->setText(QCoreApplication::translate("BookRoomDialog", "Address", nullptr));
        label_5->setText(QCoreApplication::translate("BookRoomDialog", "Id Proof", nullptr));
        btnSubmit->setText(QCoreApplication::translate("BookRoomDialog", "Submit", nullptr));
        btnCancel->setText(QCoreApplication::translate("BookRoomDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookRoomDialog: public Ui_BookRoomDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKROOMDIALOG_H
