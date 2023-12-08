import sys
from PySide6.QtWidgets import *
from PySide6.QtCore import *

class Greeting_window(QWidget):
    def __init__(self):
        QWidget.__init__(self, None)
        self.animal = ""
        vbox = QVBoxLayout()
        self.label = QLabel(self)
        self.label.setText("Hello what is your name?")
        vbox.addWidget(self.label)
        self.name_entry = QLineEdit(self)
        vbox.addWidget(self.name_entry)

        self.animal_label = QLabel(self)
        self.animal_label.setText("You prefer : ")
        vbox.addWidget(self.animal_label)
        
        self.cat_bt = QPushButton("Cat", self)
        self.cat_bt.clicked.connect(lambda: self.set_info("Cat"))
        vbox.addWidget(self.cat_bt)

        self.dog_bt = QPushButton("Dog", self)
        self.dog_bt.clicked.connect(lambda: self.set_info("Dog"))
        vbox.addWidget(self.dog_bt)

        self.animal_amount = QLabel(self)
        self.animal_amount.setText("How many of them you would have : ")
        vbox.addWidget(self.animal_amount)

        self.animal_amount_entry = QLineEdit(self)
        vbox.addWidget(self.animal_amount_entry)

        self.animal_amount_bt = QPushButton("Confirm ", self)
        self.animal_amount_bt.clicked.connect(self.generate_info)
        vbox.addWidget(self.animal_amount_bt)

        self.setLayout(vbox)
        self.show()

    def set_info(self, animal):
        self.animal = animal
        self.animal_label.setText("You prefer : " + self.animal)
        self.animal_label.show()

    def generate_info(self):
        dialog = QDialog(self)
        layout = QVBoxLayout()
        label = QLabel(self)
        label.setText("Hello " + self.name_entry.text() + ", you prefer " + self.animal + " and you would have " + self.animal_amount_entry.text() + " of them")
        layout.addWidget(label)
        close_button = QPushButton("Close", self)
        close_button.clicked.connect(dialog.close)
        layout.addWidget(close_button)
        dialog.setLayout(layout)
        dialog.show()




if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = Greeting_window()
    sys.exit(app.exec_())

