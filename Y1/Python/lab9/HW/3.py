from tkinter import *

class Circle:
    def __init__(self):
        window = Tk()
        self.list_cir = []
        self.cir_x = []
        self.cir_y = []
        self.canvas = Canvas(window,height=500,width=500)
        self.canvas.bind('<Button-1>', self.left_click)
        self.canvas.bind('<Button-3>', self.right_click)
        self.canvas.pack()
        window.mainloop()
    
    def left_click(self,pos):
        self.id = self.canvas.create_oval(pos.x-5, pos.y+5, pos.x+5, pos.y-5)
        self.list_cir.append(self.id)
        self.cir_x.append(pos.x)
        self.cir_y.append(pos.y)

    def right_click(self,pos):
        for i in self.list_cir :
            if self.cir_x[i-1]-5 <= pos.x < self.cir_x[i-1]+5 and self.cir_y[i-1]-5 <= pos.y < self.cir_y[i-1]+5:
                self.canvas.delete(i)


Circle()