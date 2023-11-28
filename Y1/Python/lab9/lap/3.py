from tkinter import *
window = Tk()

canvas = Canvas(window, width=600, height=300, bg='white')
canvas.pack(padx=20, pady=20)
Button(window,text="Clear",command=lambda: clear()).pack()


def click(click_event):
    global prev
    prev = click_event

def move(move_event):
    global prev
    canvas.create_line(prev.x, prev.y, move_event.x, move_event.y, width=2)
    prev = move_event  

def clear():
    canvas.delete("all")

canvas.bind('<Button-1>', click)
canvas.bind('<B1-Motion>', move)


window.mainloop()