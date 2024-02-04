import sys
from PySide6.QtCore import *
from PySide6.QtWidgets import *
from PySide6.QtGui import *

class Simple_drawing_window(QWidget):
    def __init__(self):
        QWidget.__init__(self, None)
        self.setWindowTitle("Simple Github Drawing by Suvijuk")
        self.rabbit = QPixmap("images/frame-12.png")
        self.ball = QPixmap("images/ball.png")

    def paintEvent(self, e):
        p = QPainter()
        p.begin(self)

        p.drawPixmap(QRect(0, 100, 320, 320), self.ball)

        p.drawPixmap(QRect(0, 50, 320, 320), self.rabbit)
        p.end()

def main():
    app = QApplication(sys.argv)

    w = Simple_drawing_window()
    w.show()

    return app.exec_()

if __name__ == "__main__":
    sys.exit(main())