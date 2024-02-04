import sys
from PySide6.QtWidgets import *
from PySide6.QtCore import *
from program_3 import Ui_Form

class TestUI(QMainWindow):
    def __init__(self):
        super().__init__()
        self.ui = Ui_Form()
        self.ui.setupUi(self)
        self.ui.num_0.clicked.connect(lambda: self.append("0"))
        self.ui.num_1.clicked.connect(lambda: self.append("1"))
        self.ui.num_2.clicked.connect(lambda: self.append("2"))
        self.ui.num_3.clicked.connect(lambda: self.append("3"))
        self.ui.num_4.clicked.connect(lambda: self.append("4"))
        self.ui.num_5.clicked.connect(lambda: self.append("5"))
        self.ui.num_6.clicked.connect(lambda: self.append("6"))
        self.ui.num_7.clicked.connect(lambda: self.append("7"))
        self.ui.num_8.clicked.connect(lambda: self.append("8"))
        self.ui.num_9.clicked.connect(lambda: self.append("9"))
        self.ui.star_button.clicked.connect(lambda: self.append("*"))
        self.ui.hashtags_button.clicked.connect(lambda: self.append("#"))
        self.ui.delete_button.clicked.connect(self.delete)
        self.ui.call_button.clicked.connect(self.call)

    def append(self, num):
        self.ui.output_text.setText(self.ui.output_text.text() + num)

    def delete(self):
        self.ui.output_text.setText(self.ui.output_text.text()[:-1])

    def call(self):
        dialog = QDialog(self)
        layout = QVBoxLayout()
        label = QLabel(self)
        label.setText("Calling : " + self.ui.output_text.text())
        layout.addWidget(label)
        close_button = QPushButton("Close", self)
        close_button.clicked.connect(dialog.close)
        layout.addWidget(close_button)
        dialog.setLayout(layout)
        dialog.show()
        print("Calling : " + self.ui.output_text.text())

    


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = TestUI()
    window.show()
    sys.exit(app.exec_())