from tkinter import *
from tkinter import messagebox

window = Tk()
money = StringVar()

def usd_to_thb():
    ans = int(money.get())
    messagebox.showinfo("Converter","{:.2f} USD = {:.2f} THB".format(ans, ans * 30))


def thb_to_usd():
    ans = int(money.get())
    messagebox.showinfo("Converter","{:.2f} THB = {:.2f} USD".format(ans, ans / 30))

e = Entry(window, textvariable = money).pack()
btUsdtoThb = Button(window, text = "USD -> THB", command = usd_to_thb).pack()
btThbtoUsb = Button(window, text = "THB -> USD", command = thb_to_usd).pack()

window.mainloop()