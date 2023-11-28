from tkinter import *
import calendar

class Finance_Calendar:
    def __init__(self,month,year) :
        window = Tk()
        window.title("Calendar")
        self.month = month
        self.year = year
        self.wid = []
        self.date = calendar.Calendar()
        days = ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat','Sun']
        for i,day in enumerate(days):
            d = Label(window,text=day,font=7)
            self.wid.append(d)
            d.grid(row=0,column=i)

        for i,day in enumerate(self.date.itermonthdays(self.year, self.month)):
            if day != 0 :
                b = Button(window,text=day,height=2,width=8,font=7)
                self.wid.append(b)
                b.grid(row=(i//7)+1,column=i%7)


        window.mainloop()

    def clear(self) :
        for w in self.wid[:]:
            w.grid_forget()
            self.wid.remove(w)

class Select_date:
    def __init__(self) :
        window = Tk()
        window.title("Select date")
        f1 = Frame(window)
        f2 = Frame(window)
        f3 = Frame(window)
        f3.pack(side = BOTTOM)
        f2.pack(side = BOTTOM)
        f1.pack(side = BOTTOM)
        self.month = StringVar()
        self.year = StringVar()

        Label(window,text="Please specify date",font=7).pack()
        Label(f1,text="Month number :",font=7).pack(side = LEFT)
        Label(f2,text="Year (A.D.) :",font=7).pack(side = LEFT)
        self.m = Entry(f1, textvariable = self.month)
        self.y = Entry(f2, textvariable = self.year)
        self.m.pack(side = LEFT)
        self.y.pack(side = LEFT)
        b = Button(f3,text="Confirm",height=1,width=10,font=5,bg="lightgreen",command= self.send_data)
        b.pack()
        window.mainloop()
    
    def send_data(self):
        Finance_Calendar(int(self.month.get()),int(self.year.get()))

Select_date()