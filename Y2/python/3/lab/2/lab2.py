import sys
from PySide6.QtWidgets import *
from PySide6.QtCore import *
from program_2 import Ui_Form

class TestUI(QMainWindow):
    def __init__(self):
        super().__init__()
        self.ui = Ui_Form()
        self.ui.setupUi(self)
        self.ui.add_button.clicked.connect(self.add)
        self.ui.sub_button.clicked.connect(self.sub)
        self.ui.reset_button.clicked.connect(self.reset)
        self.num = 0
        self.ui.num_label.setText(str(self.num))

    def add(self):
        self.num += 1
        self.ui.num_label.setText(str(self.num))

    def sub(self):
        self.num -= 1
        self.ui.num_label.setText(str(self.num))

    def reset(self):
        self.num = 0
        self.ui.num_label.setText(str(self.num))

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = TestUI()
    window.show()
    sys.exit(app.exec_())