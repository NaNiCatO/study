import js
from pyscript import document
from pyodide.ffi import create_proxy
from abc import ABC, abstractmethod
from datetime import datetime

class AdstractWidget(ABC):
    def __init__(self, element_id):
        self.element_id = element_id
        self._element = None

    @property
    def element(self):
        if self._element is None:
            self._element = document.getElementById(self.element_id)
        return self._element
    
    @abstractmethod
    def update(self, data):
        pass

def getTime():
    return datetime.now().strftime("%m/%d/%Y, %H:%M:%S")

class NotificationWidget(AdstractWidget):
    def __init__(self, element_id):
        super().__init__(element_id)

    def update(self, data):
        pass
    
    def on_click(self, event):
        text = self.input_text.value
        js.alert("Hello, " + text + " at " + getTime())

    def bath_to_USD(self, event):
        bath = self.input_text.value
        js.alert(float(bath) / 30)

    def USD_to_bath(self, event):
        USD = self.input_text.value
        js.alert(float(USD) * 30)

    def drawWidget(self):
        self.input_text = document.createElement("input", type="text")
        self.input_text.style.width = "600px"
        self.element.appendChild(self.input_text)

        # self.button = document.createElement("button")
        # self.button.innerHTML = "Click me"
        # self.button.style.width = "600px"
        # self.button.onclick = self.on_click
        # self.element.appendChild(self.button)

        self.button = document.createElement("button")
        self.button.innerHTML = "Bath to USD"
        self.button.style.width = "300px"
        self.button.onclick = self.bath_to_USD
        self.element.appendChild(self.button)

        self.button = document.createElement("button")
        self.button.innerHTML = "USD to Bath"
        self.button.style.width = "300px"
        self.button.onclick = self.USD_to_bath
        self.element.appendChild(self.button)


if __name__ == "__main__":
    widget = NotificationWidget("container")
    widget.drawWidget()