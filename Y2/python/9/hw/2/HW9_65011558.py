import js
from pyscript import document
from pyodide.ffi import create_proxy
from abc import ABC, ABCMeta, abstractmethod
from datetime import datetime
import random



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
    def drawWidget(self, event):
        pass

    @abstractmethod
    def removeWidget(self, event):
        pass


class ContorlWidget(AdstractWidget):
    def __init__(self, element_id):
        super().__init__(element_id)

    def drawWidget(self):
        arr_Q = [NotificationWidget(self.element_id), AnimationWidget(self.element_id), ColorfulAnimtionWidget(self.element_id)]
        self.button1 = document.createElement("button")
        self.button1.innerHTML = "Add Q1"
        self.button1.style.width = "100px"
        self.button1.onclick = arr_Q[0].drawWidget


        self.button2 = document.createElement("button")
        self.button2.innerHTML = "Add Q2"
        self.button2.style.width = "100px"
        self.button2.onclick = arr_Q[1].drawWidget


        self.button3 = document.createElement("button")
        self.button3.innerHTML = "Add Q3"
        self.button3.style.width = "100px"
        self.button3.onclick = arr_Q[2].drawWidget


        self.div = document.createElement("div")
        self.div.appendChild(self.button1)
        self.div.appendChild(self.button2)
        self.div.appendChild(self.button3)
        self.element.appendChild(self.div)


    def removeWidget(self, event):
        pass


class NotificationWidget(AdstractWidget):
    def __init__(self, element_id):
        super().__init__(element_id)

    def bath_to_USD(self, event):
        bath = self.input_text.value
        js.alert(float(bath) / 30)

    def USD_to_bath(self, event):
        USD = self.input_text.value
        js.alert(float(USD) * 30)

    def drawWidget(self, event):
        self.input_text = document.createElement("input", type="text")
        self.input_text.style.width = "600px"
        self.element.appendChild(self.input_text)

        self.button1 = document.createElement("button")
        self.button1.innerHTML = "Bath to USD"
        self.button1.style.width = "300px"
        self.button1.onclick = self.bath_to_USD
        self.element.appendChild(self.button1)

        self.button2 = document.createElement("button")
        self.button2.innerHTML = "USD to Bath"
        self.button2.style.width = "300px"
        self.button2.onclick = self.USD_to_bath
        self.element.appendChild(self.button2)

        self.button3 = document.createElement("button")
        self.button3.innerHTML = "remove"
        self.button3.style.width = "70%"
        self.button3.onclick = self.removeWidget
        self.element.appendChild(self.button3)

        self.div_container = document.createElement("div")
        self.div_container.appendChild(self.input_text)
        self.div_container.appendChild(self.button1)
        self.div_container.appendChild(self.button2)
        self.div_container.appendChild(self.button3)
        self.element.appendChild(self.div_container)


    def removeWidget(self, event):
        self.element.removeChild(self.div_container)



class AnimationWidget(AdstractWidget):
    def __init__(self, element_id):
        super().__init__(element_id)
        self.counter = 1
        self.interval = None

    
    def on_click(self, event):
        on_setInterval = create_proxy(self.on_setInterval)
        if self.button1.innerHTML == "pause":
            self.button1.innerHTML = "resume"
            self.interval = js.clearInterval(self.interval)
        else:
            self.button1.innerHTML = "pause"
            self.interval = js.setInterval(on_setInterval, 100)


    def on_setInterval(self):
        self.counter += 1
        if self.counter > 20:
            self.jump_sound.play()
            self.counter = 1
        self.image.src = "./images/frame-" + str(self.counter) + ".png"

    def drawWidget(self, event):
        self.image = document.createElement("img")
        self.image.style.width = "600px"
        self.image.style.height = "600px"
        self.image.src = "./images/frame-1.png"
        on_setInterval = create_proxy(self.on_setInterval)
        self.interval = js.setInterval(on_setInterval, 100)
        self.element.appendChild(self.image)


        self.jump_sound = js.Audio.new("./sounds/rabbit_jump.wav")
        self.button1 = document.createElement("button")
        self.button1.innerHTML = "pause"
        self.button1.style.width = "600px"
        self.button1.onclick = self.on_click
        self.element.appendChild(self.button1)

        self.button2 = document.createElement("button")
        self.button2.innerHTML = "remove"
        self.button2.style.width = "70%"
        self.button2.onclick = self.removeWidget
        self.element.appendChild(self.button2)

        self.div_container = document.createElement("div")
        self.div_container.appendChild(self.image)
        self.div_container.appendChild(self.button1)
        self.div_container.appendChild(self.button2)
        self.element.appendChild(self.div_container)


    def removeWidget(self, event):
        self.element.removeChild(self.div_container)
        self.interval = js.clearInterval(self.interval)

    

class ColorfulAnimtionWidget(AnimationWidget):
    def __init__(self, element_id):
        super().__init__(element_id)


    def on_click_random_color(self, event):
        self.image.style.backgroundColor = "rgb(" + str(random.randint(0,255)) + "," + str(random.randint(0,255)) + "," + str(random.randint(0,255)) + ")"


    def drawWidget(self, event):
        self.image = document.createElement("img")
        self.image.style.width = "600px"
        self.image.style.height = "600px"
        self.image.src = "./images/frame-1.png"
        on_setInterval = create_proxy(self.on_setInterval)
        self.interval = js.setInterval(on_setInterval, 100)
        self.element.appendChild(self.image)


        self.jump_sound = js.Audio.new("./sounds/rabbit_jump.wav")
        self.button1 = document.createElement("button")
        self.button1.innerHTML = "pause"
        self.button1.style.width = "600px"
        self.button1.onclick = self.on_click

        self.button_ran = document.createElement("button")
        self.button_ran.innerHTML = "random color"
        self.button_ran.style.width = "600px"
        self.button_ran.onclick = self.on_click_random_color

        self.div = document.createElement("div")
        self.div.appendChild(self.button1)
        self.div.appendChild(self.button_ran)
        self.element.appendChild(self.div)

        self.button2 = document.createElement("button")
        self.button2.innerHTML = "remove"
        self.button2.style.width = "70%"
        self.button2.onclick = self.removeWidget
        self.element.appendChild(self.button2)

        self.div_container = document.createElement("div")
        self.div_container.appendChild(self.image)
        self.div_container.appendChild(self.button1)
        self.div_container.appendChild(self.button_ran)
        self.div_container.appendChild(self.button2)
        self.element.appendChild(self.div_container)


    def removeWidget(self, event):
        self.element.removeChild(self.div_container)
        self.interval = js.clearInterval(self.interval)


if __name__ == "__main__":
    control = ContorlWidget("container")
    control.drawWidget()
    