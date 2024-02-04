# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'program_2.ui'
##
## Created by: Qt User Interface Compiler version 6.6.0
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QApplication, QLabel, QPushButton, QSizePolicy,
    QWidget)

class Ui_Form(object):
    def setupUi(self, Form):
        if not Form.objectName():
            Form.setObjectName(u"Form")
        Form.resize(400, 300)
        self.num_label = QLabel(Form)
        self.num_label.setObjectName(u"num_label")
        self.num_label.setGeometry(QRect(10, 10, 151, 281))
        self.num_label.setBaseSize(QSize(0, 0))
        font = QFont()
        font.setPointSize(36)
        self.num_label.setFont(font)
        self.num_label.setAlignment(Qt.AlignCenter)
        self.add_button = QPushButton(Form)
        self.add_button.setObjectName(u"add_button")
        self.add_button.setGeometry(QRect(210, 20, 151, 81))
        self.sub_button = QPushButton(Form)
        self.sub_button.setObjectName(u"sub_button")
        self.sub_button.setGeometry(QRect(210, 110, 151, 81))
        self.reset_button = QPushButton(Form)
        self.reset_button.setObjectName(u"reset_button")
        self.reset_button.setGeometry(QRect(210, 200, 151, 81))

        self.retranslateUi(Form)

        QMetaObject.connectSlotsByName(Form)
    # setupUi

    def retranslateUi(self, Form):
        Form.setWindowTitle(QCoreApplication.translate("Form", u"Form", None))
        self.num_label.setText(QCoreApplication.translate("Form", u"0", None))
        self.add_button.setText(QCoreApplication.translate("Form", u"+", None))
        self.sub_button.setText(QCoreApplication.translate("Form", u"-", None))
        self.reset_button.setText(QCoreApplication.translate("Form", u"Reset", None))
    # retranslateUi

