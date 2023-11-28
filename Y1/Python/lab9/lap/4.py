from tkinter import *
from tkinter import messagebox
import random
colors = ["red", "orange", "yellow", "green", "blue", "indigo", "violet"]
window = Tk()
window.title('PythonGuides')
canvas = Canvas(window,height=500,width=500,bg="white")
canvas.pack()
canvas.create_rectangle(50, 50, 450, 250,outline="black")
def click(click_event):
    if 50 <= click_event.x <= 450 and 50 <= click_event.y <= 250:
        canvas.create_oval(click_event.x-5, click_event.y+5,click_event.x+5, click_event.y-5,fill=random.choice(colors))
    else:
        messagebox.showwarning("Warning", "not in the rectangle")
canvas.bind('<Button-1>', click)


window.mainloop()