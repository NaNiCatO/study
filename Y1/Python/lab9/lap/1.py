from tkinter import *

class Buttonclick():
    def __init__(self,count):
        self.count = count
        window = Tk()
        self.label = Label(window, text = self.count)
        p = Button(window, text = "+",command = self.plus)
        m = Button(window, text = "-",command = self.minus)
        reset = Button(window, text = "reset", command = self.reset)
        self.label.pack()
        p.pack()
        m.pack()
        reset.pack()
        window.mainloop()
    def plus(self):
            self.count += 1
            self.label.config(text=self.count)
    def minus(self):
            self.count -= 1
            self.label.config(text=self.count)
    def reset(self):
            self.count = 0
            self.label.config(text=self.count)


Buttonclick(0)