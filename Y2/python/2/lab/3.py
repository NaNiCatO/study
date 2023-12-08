import sys
from PySide6.QtWidgets import *
from PySide6.QtCore import *
import time

class Simple_timer_window(QWidget):
    def __init__(self):
        QWidget.__init__(self, None)
        self.num = 0
        vbox = QVBoxLayout()
        self.label = QLabel(self)
        self.label.setText(str(self.num))
        vbox.addWidget(self.label)
        self.currentTime = QLabel(self)
        self.currentTime.setText("")
        vbox.addWidget(self.currentTime)
        timer = QTimer(self)
        timer.timeout.connect(self.update)
        timer.start(500)
        self.setLayout(vbox)
        self.show()

    def update(self):
        self.num += 1
        if self.num > 100:
            self.num = 0
        self.label.setText(str(self.num))
        self.currentTime.setText(time.strftime("%X"))

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = Simple_timer_window()
    sys.exit(app.exec_())