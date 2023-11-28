/********************************************************************************
** Form generated from reading UI file 'roomavailabledialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMAVAILABLEDIALOG_H
#define UI_ROOMAVAILABLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_RoomAvailableDialog
{
public:
    QGroupBox *groupBox;
    QLabel *lbl101;
    QLabel *lbl102;
    QLabel *lbl103;
    QLabel *lbl104;
    QLabel *lbl105;
    QLabel *lbl204;
    QLabel *lbl205;
    QLabel *lbl203;
    QLabel *lbl201;
    QLabel *lbl202;
    QLabel *lblinfo;

    void setupUi(QDialog *RoomAvailableDialog)
    {
        if (RoomAvailableDialog->objectName().isEmpty())
            RoomAvailableDialog->setObjectName("RoomAvailableDialog");
        RoomAvailableDialog->setWindowModality(Qt::WindowModal);
        RoomAvailableDialog->setEnabled(false);
        RoomAvailableDialog->resize(380, 200);
        RoomAvailableDialog->setAutoFillBackground(true);
        groupBox = new QGroupBox(RoomAvailableDialog);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(40, 10, 311, 151));
        lbl101 = new QLabel(groupBox);
        lbl101->setObjectName("lbl101");
        lbl101->setGeometry(QRect(10, 30, 50, 50));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        lbl101->setFont(font);
        lbl101->setTextFormat(Qt::RichText);
        lbl101->setScaledContents(true);
        lbl101->setAlignment(Qt::AlignCenter);
        lbl102 = new QLabel(groupBox);
        lbl102->setObjectName("lbl102");
        lbl102->setGeometry(QRect(70, 30, 50, 50));
        lbl102->setFont(font);
        lbl102->setScaledContents(true);
        lbl102->setAlignment(Qt::AlignCenter);
        lbl103 = new QLabel(groupBox);
        lbl103->setObjectName("lbl103");
        lbl103->setGeometry(QRect(130, 30, 50, 50));
        lbl103->setFont(font);
        lbl103->setScaledContents(true);
        lbl103->setAlignment(Qt::AlignCenter);
        lbl104 = new QLabel(groupBox);
        lbl104->setObjectName("lbl104");
        lbl104->setGeometry(QRect(190, 30, 50, 50));
        lbl104->setFont(font);
        lbl104->setScaledContents(true);
        lbl104->setAlignment(Qt::AlignCenter);
        lbl105 = new QLabel(groupBox);
        lbl105->setObjectName("lbl105");
        lbl105->setGeometry(QRect(250, 30, 50, 50));
        lbl105->setFont(font);
        lbl105->setScaledContents(true);
        lbl105->setAlignment(Qt::AlignCenter);
        lbl204 = new QLabel(groupBox);
        lbl204->setObjectName("lbl204");
        lbl204->setGeometry(QRect(190, 90, 50, 50));
        lbl204->setFont(font);
        lbl204->setScaledContents(true);
        lbl204->setAlignment(Qt::AlignCenter);
        lbl205 = new QLabel(groupBox);
        lbl205->setObjectName("lbl205");
        lbl205->setGeometry(QRect(250, 90, 50, 50));
        lbl205->setFont(font);
        lbl205->setScaledContents(true);
        lbl205->setAlignment(Qt::AlignCenter);
        lbl203 = new QLabel(groupBox);
        lbl203->setObjectName("lbl203");
        lbl203->setGeometry(QRect(130, 90, 50, 50));
        lbl203->setFont(font);
        lbl203->setScaledContents(true);
        lbl203->setAlignment(Qt::AlignCenter);
        lbl201 = new QLabel(groupBox);
        lbl201->setObjectName("lbl201");
        lbl201->setGeometry(QRect(10, 90, 50, 50));
        lbl201->setFont(font);
        lbl201->setScaledContents(true);
        lbl201->setAlignment(Qt::AlignCenter);
        lbl202 = new QLabel(groupBox);
        lbl202->setObjectName("lbl202");
        lbl202->setGeometry(QRect(70, 90, 50, 50));
        lbl202->setFont(font);
        lbl202->setScaledContents(true);
        lbl202->setAlignment(Qt::AlignCenter);
        lblinfo = new QLabel(RoomAvailableDialog);
        lblinfo->setObjectName("lblinfo");
        lblinfo->setGeometry(QRect(40, 170, 47, 13));

        retranslateUi(RoomAvailableDialog);

        QMetaObject::connectSlotsByName(RoomAvailableDialog);
    } // setupUi

    void retranslateUi(QDialog *RoomAvailableDialog)
    {
        RoomAvailableDialog->setWindowTitle(QCoreApplication::translate("RoomAvailableDialog", "Available Rooms", nullptr));
        groupBox->setTitle(QCoreApplication::translate("RoomAvailableDialog", "Rooms Availability", nullptr));
        lbl101->setText(QCoreApplication::translate("RoomAvailableDialog", "101", nullptr));
        lbl102->setText(QCoreApplication::translate("RoomAvailableDialog", "102", nullptr));
        lbl103->setText(QCoreApplication::translate("RoomAvailableDialog", "103", nullptr));
        lbl104->setText(QCoreApplication::translate("RoomAvailableDialog", "104", nullptr));
        lbl105->setText(QCoreApplication::translate("RoomAvailableDialog", "105", nullptr));
        lbl204->setText(QCoreApplication::translate("RoomAvailableDialog", "204", nullptr));
        lbl205->setText(QCoreApplication::translate("RoomAvailableDialog", "205", nullptr));
        lbl203->setText(QCoreApplication::translate("RoomAvailableDialog", "203", nullptr));
        lbl201->setText(QCoreApplication::translate("RoomAvailableDialog", "201", nullptr));
        lbl202->setText(QCoreApplication::translate("RoomAvailableDialog", "202", nullptr));
        lblinfo->setText(QCoreApplication::translate("RoomAvailableDialog", "Available", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoomAvailableDialog: public Ui_RoomAvailableDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMAVAILABLEDIALOG_H
