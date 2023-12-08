import sys 
from PySide6.QtWidgets import QApplication, QWidget, QPushButton

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)


    window = QWidget()
    window.resize(250, 150)
    window.move(300, 300)
    window.setWindowTitle("Simple")
    button = QPushButton("Hello, World!", window)
    button.move(50, 50)

    window.show()
    sys.exit(app.exec_())