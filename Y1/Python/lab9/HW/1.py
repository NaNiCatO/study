from tkinter import *
from tkinter import messagebox

class calculator:
    def __init__(self):
        self.ans = ""
        window = Tk()
        window.title("KMITL Phone")
        self.text = Label(window,text=self.ans,font=20)
        self.text.grid(row=0,column=1)
        Button(window,text= "1",font=20,height=2,width=10,command=lambda :self.press_num(1)).grid(row=1,column=0)
        Button(window,text= "2",font=20,height=2,width=10,command=lambda :self.press_num(2)).grid(row=1,column=1)
        Button(window,text= "3",font=20,height=2,width=10,command=lambda :self.press_num(3)).grid(row=1,column=2)
        Button(window,text= "4",font=20,height=2,width=10,command=lambda :self.press_num(4)).grid(row=2,column=0)
        Button(window,text= "5",font=20,height=2,width=10,command=lambda :self.press_num(5)).grid(row=2,column=1)
        Button(window,text= "6",font=20,height=2,width=10,command=lambda :self.press_num(6)).grid(row=2,column=2)
        Button(window,text= "7",font=20,height=2,width=10,command=lambda :self.press_num(7)).grid(row=3,column=0)
        Button(window,text= "8",font=20,height=2,width=10,command=lambda :self.press_num(8)).grid(row=3,column=1)
        Button(window,text= "9",font=20,height=2,width=10,command=lambda :self.press_num(9)).grid(row=3,column=2)
        Button(window,text= "*",font=20,height=2,width=10,command=lambda :self.press_num("*")).grid(row=4,column=0)
        Button(window,text= "0",font=20,height=2,width=10,command=lambda :self.press_num(0)).grid(row=4,column=1)
        Button(window,text= "#",font=20,height=2,width=10,command=lambda :self.press_num("#")).grid(row=4,column=2)
        Button(window,text= "Talk",font=20,height=2,width=10,command=self.press_talk).grid(row=5,column=0)
        Button(window,text= "<",font=20,height=2,width=10,command=self.press_del).grid(row=5,column=2)
        window.mainloop()

    def press_num(self,x):
        self.ans = self.ans + str(x)
        self.text.config(text=self.ans)

    def press_del(self):
        self.ans = self.ans[:-1]
        self.text.config(text=self.ans)

    def press_talk(self):
        messagebox.showinfo("Dialling","Dialling <<{}>>".format(self.ans))


calculator()