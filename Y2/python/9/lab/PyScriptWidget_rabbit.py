import js
from pyscript import document
from pyodide.ffi import create_proxy
from abc import ABC, abstractmethod
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
    def update(self, data):
        pass

def getTime():
    return datetime.now().strftime("%m/%d/%Y, %H:%M:%S")

class AnimationWidget(AdstractWidget):
    def __init__(self, element_id):
        super().__init__(element_id)
        self.counter = 1
        self.interval = None

    def update(self, data):
        pass
    
    def on_click(self, event):
        on_setInterval = create_proxy(self.on_setInterval)
        if self.button.innerHTML == "pause":
            self.button.innerHTML = "resume"
            self.interval = js.clearInterval(self.interval)
        else:
            self.button.innerHTML = "pause"
            self.interval = js.setInterval(on_setInterval, 100)


    def on_setInterval(self):
        self.counter += 1
        if self.counter > 20:
            self.jump_sound.play()
            self.counter = 1
        self.image.src = "./images/frame-" + str(self.counter) + ".png"

    def drawWidget(self):
        self.image = document.createElement("img")
        self.image.style.width = "600px"
        self.image.style.height = "600px"
        self.image.src = "./images/frame-1.png"
        on_setInterval = create_proxy(self.on_setInterval)
        self.interval = js.setInterval(on_setInterval, 100)
        self.element.appendChild(self.image)


        self.jump_sound = js.Audio.new("./sounds/rabbit_jump.wav")
        self.button = document.createElement("button")
        self.button.innerHTML = "pause"
        self.button.style.width = "600px"
        self.button.onclick = self.on_click
        self.element.appendChild(self.button)



class ColorfulAnimtionWidget(AnimationWidget):
    def __init__(self, element_id):
        super().__init__(element_id)

    def update(self, data):
        pass


    def on_click_random_color(self, event):
        self.image.style.backgroundColor = "rgb(" + str(random.randint(0,255)) + "," + str(random.randint(0,255)) + "," + str(random.randint(0,255)) + ")"


    def drawWidget(self):
        self.image = document.createElement("img")
        self.image.style.width = "600px"
        self.image.style.height = "600px"
        self.image.src = "./images/frame-1.png"
        on_setInterval = create_proxy(self.on_setInterval)
        self.interval = js.setInterval(on_setInterval, 100)
        self.element.appendChild(self.image)


        self.jump_sound = js.Audio.new("./sounds/rabbit_jump.wav")
        self.button = document.createElement("button")
        self.button.innerHTML = "pause"
        self.button.style.width = "600px"
        self.button.onclick = self.on_click
        self.element.appendChild(self.button)

        self.button_ran = document.createElement("button")
        self.button_ran.innerHTML = "random color"
        self.button_ran.style.width = "600px"
        self.button_ran.onclick = self.on_click_random_color
        self.element.appendChild(self.button_ran)

        self.div = document.createElement("div")
        self.div.appendChild(self.button)
        self.div.appendChild(self.button_ran)
        self.element.appendChild(self.div)

if __name__ == "__main__":
    widget = ColorfulAnimtionWidget("container")
    widget.drawWidget()
