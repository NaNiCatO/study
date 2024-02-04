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

class Table_frame(AdstractWidget):
    def __init__(self, element_id):
        super().__init__(element_id)
        self.jump_sound = js.Audio.new("./sounds/rabbit_jump.wav")
        self.counter = 0
        self.interval = None
        self.arr_frame = []
        self.speed = 100
        

    def update(self, data):
        pass

    def on_setInterval(self):
        self.counter = self.counter + 1
        if self.counter > len(self.arr_frame):
            self.counter = 0
            self.jump_sound.play()
            
        self.image.src = "./images/frame-" + str(self.arr_frame[self.counter-1]) + ".png"


    def on_click_slower(self, event):
        self.speed = self.speed + 10
        js.clearInterval(self.interval)
        on_setInterval = create_proxy(self.on_setInterval)
        self.interval = js.setInterval(on_setInterval, self.speed)

    def on_click_faster(self, event):
        self.speed = self.speed - 10
        js.clearInterval(self.interval)
        on_setInterval = create_proxy(self.on_setInterval)
        self.interval = js.setInterval(on_setInterval, self.speed)

    def on_click_reset(self, event):
        self.arr_frame = range(1, 21)
        self.counter = 0
        self.speed = 100
        js.clearInterval(self.interval)
        on_setInterval = create_proxy(self.on_setInterval)
        self.interval = js.setInterval(on_setInterval, self.speed)
        for i in range(1, 21):
            document.getElementById(i).style.backgroundColor = "white"

    def drawTableFrame(self):
        self.table = document.createElement("table")
        self.table.style.width = "70%"
        self.table.style.height = "20%"
        self.table.style.border = "1px solid black"
        self.table.style.textAlign = "center"
        self.table.style.backgroundColor = "white"
        self.table.style.borderCollapse = "collapse"
        self.element.appendChild(self.table)
        index = 1
        for i in range(4):
            self.tr = document.createElement("tr")
            self.table.appendChild(self.tr)
            for j in range(5):
                self.td = document.createElement("td")
                self.td.style.border = "1px solid black"
                self.td.innerHTML = str(index)
                self.td.id = str(index)
                self.td.onclick = self.on_click_change_color
                self.arr_frame.append(index)
                self.tr.appendChild(self.td)
                index = index + 1

    
    def on_click_change_color(self, event):
        id = int(event.target.id)
        if id in self.arr_frame:
            self.arr_frame.remove(id)
            document.getElementById(id).style.backgroundColor = "red"
        else:
            self.arr_frame.append(id)
            document.getElementById(id).style.backgroundColor = "white"
        self.arr_frame.sort()

    def drawWidget(self):
        self.image = document.createElement("img")
        self.image.style.width = "600px"
        self.image.style.height = "600px"
        self.image.src = "./images/frame-1.png"
        
        on_setInterval = create_proxy(self.on_setInterval)
        self.interval = js.setInterval(on_setInterval, self.speed)

        self.topic = document.createElement("h1")
        self.topic.innerHTML = "Frame simulation"
        self.topic.style.width = "50%"

        self.div = document.createElement("div")
        self.div.style.display = "flex"
        self.div.style.alignItems = "center"
        self.div.style.textAlign = "center"
        self.div.appendChild(self.image)
        self.div.appendChild(self.topic)
        self.element.appendChild(self.div)

        
        self.button_slow = document.createElement("button")
        self.button_slow.innerHTML = "slower"
        self.button_slow.style.width = "33%"
        self.button_slow.onclick = self.on_click_slower


        self.button_ran = document.createElement("button")
        self.button_ran.innerHTML = "faster"
        self.button_ran.style.width = "33%"
        self.button_ran.onclick = self.on_click_faster


        self.button = document.createElement("button")
        self.button.innerHTML = "reset"
        self.button.style.width = "33%"
        self.button.onclick = self.on_click_reset


        self.div = document.createElement("div")
        self.div.appendChild(self.button_slow)
        self.div.appendChild(self.button_ran)
        self.div.appendChild(self.button)
        self.element.appendChild(self.div)

if __name__ == "__main__":
    widget = Table_frame("container")
    widget.drawTableFrame()
    widget.drawWidget()
    