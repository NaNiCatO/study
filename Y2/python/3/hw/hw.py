import sys
import math
from PySide6.QtWidgets import *
from PySide6.QtCore import *
from program import Ui_MainWindow


class calculator(QMainWindow):
    def __init__(self):
        super().__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.equation = ""

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
        self.ui.add_button.clicked.connect(lambda: self.append("+"))
        self.ui.sub_button.clicked.connect(lambda: self.append("-"))
        self.ui.mul_button.clicked.connect(lambda: self.append("*"))
        self.ui.divide_button.clicked.connect(lambda: self.append("/"))
        self.ui.pow_button.clicked.connect(lambda: self.append("**"))
        self.ui.delete_button.clicked.connect(self.delete)
        self.ui.calculate_button.clicked.connect(self.calculate)
        self.ui.clear_button.clicked.connect(self.clear)
        self.ui.sin_button.clicked.connect(self.sin)
        self.ui.cos_button.clicked.connect(self.cos)
        self.ui.tan_button.clicked.connect(self.tan)
        self.ui.factorial_button.clicked.connect(self.factorial)
        self.ui.sqrt_button.clicked.connect(self.sqrt)
        self.ui.invert_button.clicked.connect(self.invert)
        self.ui.sum_button.clicked.connect(self.summarize)

    def append(self, num):
        self.ui.output_text.setText(self.ui.output_text.text() + num)

    def delete(self):
        self.ui.output_text.setText(self.ui.output_text.text()[:-1])

    def calculate(self):
        #clear the multiple 0 at the start of the string
        while self.ui.output_text.text()[0] == "0" and len(self.ui.output_text.text()) > 1:
            self.ui.output_text.setText(self.ui.output_text.text()[1:])

        self.equation = self.ui.output_text.text()
        self.ui.output_text.setText(str(eval(self.ui.output_text.text())))

    def clear(self):
        self.ui.output_text.setText("")
        self.equation = self.ui.output_text.text()

    def sin(self):
        self.equation = "sin(" + self.ui.output_text.text() + ")"
        self.ui.output_text.setText(str(math.sin(float(self.ui.output_text.text()))))

    def cos(self):
        self.equation = "cos(" + self.ui.output_text.text() + ")"
        self.ui.output_text.setText(str(math.cos(float(self.ui.output_text.text()))))

    def tan(self):
        self.equation = "tan(" + self.ui.output_text.text() + ")"
        self.ui.output_text.setText(str(math.tan(float(self.ui.output_text.text()))))

    def factorial(self):
        self.equation = self.ui.output_text.text() + "!"
        self.ui.output_text.setText(str(math.factorial(int(self.ui.output_text.text()))))
    
    def sqrt(self):
        self.equation = "sqrt(" + self.ui.output_text.text() + ")"
        self.ui.output_text.setText(str(math.sqrt(float(self.ui.output_text.text()))))

    def invert(self):
        self.equation = "1/" + self.ui.output_text.text()
        self.ui.output_text.setText(str(1/float(self.ui.output_text.text())))

    def summarize(self):
        dialog = QDialog(self)
        layout = QVBoxLayout()
        label_equa = QLabel(self)
        label_equa.setText("Equation : " + self.equation)
        layout.addWidget(label_equa)
        label_result = QLabel(self)
        label_result.setText("Result : " + self.ui.output_text.text())
        layout.addWidget(label_result)
        close_button = QPushButton("Close", self)
        close_button.clicked.connect(dialog.close)
        layout.addWidget(close_button)
        dialog.setLayout(layout)
        dialog.show()

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = calculator()
    window.show()
    sys.exit(app.exec_())
