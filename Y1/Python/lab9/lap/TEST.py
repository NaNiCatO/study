from tkinter import *
window = Tk()
#self.ans = IntVar()
window.title("Currency Converter")
#Entry(window, textvariable= self.ans).pack
Button(window, text="USD -> THB").pack()
Button(window, text="THB -> USD").pack()
window.mainloop()