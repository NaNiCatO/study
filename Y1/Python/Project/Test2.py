from tkinter import *
from tkinter import messagebox
from tkinter import filedialog
import calendar
import abc
import turtle
import pickle
#Error type
class Enter_number(Exception):
    def __init__(self):
        messagebox.showerror(title=None, message="Please enter the number")

class Enter_month(Exception):
    def __init__(self):
        messagebox.showerror(title=None, message="Please enter month number 1-12")

class Enter_pos_integer(Exception):
    def __init__(self):
        messagebox.showerror(title=None, message="Please enter the positive integer")        

class Enter_integer(Exception):
    def __init__(self):
        messagebox.showerror(title=None, message="Please enter the integer")


class Declare_variable(abc.ABC):
    def __init__(self, month, year, data):
        self.month = month
        self.year = year
        self.date = calendar.Calendar()
        self.curent_date = 0
        if data == {} :
            for day in self.date.itermonthdays(self.year, self.month):
                if day != 0 :
                    self.data[day] = [0,0]
        else :
            self.data = data

class Income_and_Expenses(Declare_variable):
    def __init__(self, month, year, data, id = 0):
        Declare_variable.__init__(self, month, year, data)
        self.manage_data = Tk()
        self.manage_data.title("income and expenses")
        f1 = Frame(self.manage_data)
        f2 = Frame(self.manage_data)
        f3 = Frame(self.manage_data)
        f3.pack(side = BOTTOM)
        f2.pack(side = BOTTOM)
        f1.pack(side = BOTTOM)

        Label(self.manage_data,text="Please enter the amount",font = 7).pack()
        Label(f1,text="Income :",font=7).pack(side = LEFT)
        Label(f2,text="Expenses :",font=7).pack(side = LEFT)
        self.In = Entry(f1)
        self.Ex = Entry(f2)
        b = Button(f3,text="Confirm",height=1,width=10,font=5,bg="lightgreen",command=lambda : self.store_data(id))
        self.In.pack(side = LEFT)
        self.Ex.pack(side = LEFT)
        b.pack()
        self.manage_data.mainloop()


    def store_data(self,id):
        try :
            if self.In.get() == "" :
                if eval(self.Ex.get()) < 0:
                    raise Enter_pos_integer
                if id == "add_all":
                    for day in self.date.itermonthdays(self.year, self.month):
                        if day != 0 :
                            self.data[day] = [self.data[day][0],self.data[day][1]+eval(self.Ex.get())]
                elif id == "subtract_all":
                    for day in self.date.itermonthdays(self.year, self.month):
                        if day != 0 :
                            self.data[day] = [self.data[day][0],self.data[day][1]-eval(self.Ex.get())]
                elif id != 0:
                    self.data[id] = [self.data[id][0],eval(self.Ex.get())]
                else : 
                    for day in self.date.itermonthdays(self.year, self.month):
                        if day != 0 :
                            self.data[day] = [self.data[day][0],eval(self.Ex.get())]
            elif self.Ex.get() == "" :
                if eval(self.In.get()) < 0 :
                    raise Enter_pos_integer
                if id == "add_all":
                    for day in self.date.itermonthdays(self.year, self.month):
                        if day != 0 :
                            self.data[day] = [self.data[day][0]+eval(self.In.get()),self.data[day][1]]
                elif id == "subtract_all":
                    for day in self.date.itermonthdays(self.year, self.month):
                        if day != 0 :
                            self.data[day] = [self.data[day][0]-eval(self.In.get()),self.data[day][1]]
                elif id != 0:
                    self.data[id] = [eval(self.In.get()),self.data[id][1]]
                else : 
                    for day in self.date.itermonthdays(self.year, self.month):
                        if day != 0 :
                            self.data[day] = [eval(self.In.get()),self.data[day][1]]
            else :
                if eval(self.In.get()) < 0 or eval(self.Ex.get()) < 0:
                    raise Enter_pos_integer
                if id == "add_all":
                    for day in self.date.itermonthdays(self.year, self.month):
                        if day != 0 :
                            self.data[day] = [self.data[day][0]+eval(self.In.get()),self.data[day][1]+eval(self.Ex.get())]
                elif id == "subtract_all":
                    for day in self.date.itermonthdays(self.year, self.month):
                        if day != 0 :
                            self.data[day] = [self.data[day][0]-eval(self.In.get()),self.data[day][1]-eval(self.Ex.get())]
                elif id != 0:
                    self.data[id] = [eval(self.In.get()),eval(self.Ex.get())]
                else : 
                    for day in self.date.itermonthdays(self.year, self.month):
                        if day != 0 :
                            self.data[day] = [eval(self.In.get()),eval(self.Ex.get())]
            self.manage_data.destroy()
        except Enter_pos_integer:
            pass
        except :
            raise Enter_number


class Generate_table(Declare_variable):
    def __init__(self,month,year,data) :
        super().__init__(month, year, data)
        self.window = Tk()
        self.window.title("Calendar")
        self.info = Frame(self.window)
        self.info1 = Frame(self.window)
        self.table = Frame(self.window)
        self.table.grid(row=0)
        self.info.grid(row=1)
        self.info1.grid(row=2)
        self.wid = []
        days = ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat','Sun']
        for i,day in enumerate(days):
            d = Label(self.table,text=day,font=7,width=8,bg="#555555",fg="white")
            self.wid.append(d)
            d.grid(row=0,column=i)
        for i,day in enumerate(self.date.itermonthdays(self.year, self.month)):
            if day != 0 :
                b = Button(self.table,text=day,height=2,width=8,font=7,command=lambda day=day : self.press_button(day),bg="#333333",fg="white")
                self.wid.append(b)
                b.grid(row=(i//7)+1,column=i%7)

    
    @abc.abstractclassmethod
    def press_button(self):
        pass

    def find_average(self,index):
        text = ["income","expenses"]
        aver = 0
        c = 0 
        for i in self.data.values():
            aver += int(i[index])
            c += 1
        ans = aver/c
        return [text[index],ans]

    def find_saving(self):
        dict_saving = {}
        average_saving = 0
        c = 0 
        for k,v in self.data.items():
            dict_saving[k] = v[0]-v[1]
            average_saving += (v[0]-v[1])
            c += 1
        ans = average_saving/c
        return [dict_saving,ans]


class Finance_Calendar(Income_and_Expenses,Generate_table):
    def __init__(self,month,year,data) :
        Generate_table.__init__(self, month, year, data)
        Button(self.info1,text="Save",height=1,width=10,font=5,command=self.save).grid(row=0,column=0)
        Button(self.info,text="Edit value",height=2,width=8,font=3,bg="#FFFFE0",command=lambda :Edit_value(self.month,self.year,self.data)).grid(row=1,column=0)
        Button(self.info,text="average\nincome",height=2,width=8,font=3,bg="lightblue",command=lambda : self.find_average(0)).grid(row=1,column=1)
        Button(self.info,text="average\nexpenses",height=2,width=8,font=3,bg="lightblue",command=lambda : self.find_average(1)).grid(row=1,column=2)
        Button(self.info,text="Concentration",height=2,width=12,font=3,bg="lightblue",command=lambda :Show_concentration(self.month,self.year,self.data)).grid(row=1,column=3)
        Button(self.info,text="Ratio Graph",height=2,width=10,font=3,bg="lightblue",command=lambda :Show_Graph(self.data)).grid(row=1,column=4)
        Button(self.info,text="Clear data",height=2,width=8,font=3,bg="#FFCCCB",command=self.clear_data).grid(row=1,column=5)
        self.window.mainloop()

    def press_button(self,id):
        Income_and_Expenses.__init__(self,self.month,self.year,self.data,id)


    #data zone
    def clear_data(self):
        check = messagebox.askquestion(title=None, message="Are you sure want to clear the data?",)
        if check == "yes":
            for day in self.date.itermonthdays(self.year, self.month):
                if day != 0 :
                    self.data[day] = [0,0]

    def find_average(self,index):
        value = Generate_table.find_average(self, index)
        messagebox.showinfo(title="Average", message="Average {} = {:.2f}".format(value[0],value[1]))

    def save(self):
        filepath = filedialog.asksaveasfilename(filetypes=[('All Files', '*.*')], title="Save File")
        if filepath is None:
            print("\nFile not saved\n")
        else:
            file = open(filepath, 'wb')
            pickle.dump([self.month,self.year,self.data], file)
            file.close() 
            print("\nFile has been saved\n")


class Edit_value(Income_and_Expenses,Declare_variable):
    def __init__(self, month, year, data):
        Declare_variable.__init__(self, month, year, data)
        self.window = Tk()
        self.window.title("Edit value")
        Button(self.window,text="Set value for all",height=2,width=16,font=3,bg="#FFFFE0",command=self.set_for_all).grid(row=1,column=0)
        Button(self.window,text="Add value for all",height=2,width=16,font=3,bg="lightgreen",command=self.add_for_all).grid(row=1,column=1)
        Button(self.window,text="Subtract value for all",height=2,width=16,font=3,bg="#FFCCCB",command=self.subtract_for_all).grid(row=1,column=2)
        self.window.mainloop()
        
    def set_for_all(self):
        self.window.destroy()
        Income_and_Expenses.__init__(self,self.month,self.year,self.data)

    def add_for_all(self):
        self.window.destroy()
        Income_and_Expenses.__init__(self,self.month,self.year,self.data,"add_all")

    
    def subtract_for_all(self):
        self.window.destroy()
        Income_and_Expenses.__init__(self,self.month,self.year,self.data,"subtract_all")


class Select_date(Finance_Calendar):
    def __init__(self) :
        self.select_date = Tk()
        self.select_date.title("Select date")
        f1 = Frame(self.select_date)
        f2 = Frame(self.select_date)
        f3 = Frame(self.select_date)
        f3.pack(side = BOTTOM)
        f2.pack(side = BOTTOM)
        f1.pack(side = BOTTOM)
        self.data = {}

        Label(self.select_date,text="Please specify date",font=7).pack()
        Label(f1,text="Month number :",font=7).pack(side = LEFT)
        Label(f2,text="Year (A.D.) :",font=7).pack(side = LEFT)
        self.m = Entry(f1)
        self.y = Entry(f2)
        self.m.pack(side = LEFT)
        self.y.pack(side = LEFT)
        b = Button(f3,text="Confirm",height=1,width=10,font=5,bg="lightgreen",command= self.send_data)
        b.pack()
        self.select_date.mainloop()
    
    def send_data(self):
        try :
            month = self.m.get()
            year = self.y.get()
            self.select_date.destroy()
            if int(month) < 0 and int(year) < 0 :
                raise Enter_pos_integer
            elif 1 <= int(month) <= 12 :
                Finance_Calendar.__init__(self,int(month),int(year),self.data)
            else :
                raise Enter_month
        except Enter_month :
            pass
        except Enter_pos_integer :
            pass
        except :
            raise Enter_integer





class Show_concentration(Generate_table):
    def __init__(self, month, year, data):
        super().__init__(month, year, data)
        Button(self.info,text="Saving",height=2,width=8,font=3,bg="#FFFFE0",command=lambda :self.find_average(2)).grid(row=1,column=0)
        Button(self.info,text="Income",height=2,width=8,font=3,bg="lightgreen",command=lambda : self.find_average(0)).grid(row=1,column=1)
        Button(self.info,text="Expenses",height=2,width=8,font=3,bg="#FFCCCB",command=lambda : self.find_average(1)).grid(row=1,column=2)
        Button(self.info,text="Show info",height=2,width=8,font=3,command=self.Show_info).grid(row=1,column=3)


    def press_button(self,id):
        print(id)
        messagebox.showinfo(title="Day {} info".format(id), message="Income = {:.2f}\nExpenses = {:.2f}".format(self.data[id][0],self.data[id][1]))

    def find_average(self,index):
        color_list = [["#B3CF99","#429B46","#658354"],["#F1A7A7","#EA7B7B","#E34F4F"],["#FFEE7E","#FFE449","#FFFD0E"]]
        if index == 2:
            value = Generate_table.find_saving(self)
            #                   120%                150%               170%
            value_list = [(value[1]*120)/100,(value[1]*150)/100,(value[1]*170)/100]
            for day in self.date.itermonthdays(self.year, self.month):
                if day != 0 :
                    if value[0][day] <= value[1] :
                        self.wid[day+6].config(bg = "white",fg="black")

                    elif float(value[0][day]) <= value_list[0]:
                        self.wid[day+6].config(bg = color_list[index][0],fg="black")

                    elif float(value[0][day]) <= value_list[1]:
                        self.wid[day+6].config(bg = color_list[index][1],fg="black")

                    else :
                        self.wid[day+6].config(bg = color_list[index][2],fg="black")
        else:
            value = Generate_table.find_average(self, index)
            #                   120%              150%                 170%
            value_list = [(value[1]*120)/100,(value[1]*150)/100,(value[1]*170)/100]
            for day in self.date.itermonthdays(self.year, self.month):
                if day != 0 :
                    if self.data[day][index] <= value[1] :
                        self.wid[day+6].config(bg = "white",fg="black")

                    elif self.data[day][index] <= value_list[0]:
                        self.wid[day+6].config(bg = color_list[index][0],fg="black")

                    elif self.data[day][index] <= value_list[1]:
                        self.wid[day+6].config(bg = color_list[index][1],fg="black")

                    else :
                        self.wid[day+6].config(bg = color_list[index][2],fg="black")

    def Show_info(self):
        window = Tk()
        window.title("Calendar")
        days = ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat','Sun']
        for i,day in enumerate(days):
            d = Label(window,text=day,height=2,width=15,font=7,bg="#555555",fg="white")
            d.grid(row=0,column=i)
        for i,day in enumerate(self.date.itermonthdays(self.year, self.month)):
            if day != 0 :
                b = Button(window,text="Income = "+str(self.data[day][0])+"\nExpenses = "+str(self.data[day][1]),height=3,width=15,font=3,bg="#333333",fg="white")
                b.grid(row=(i//7)+1,column=i%7)
        window.mainloop()

class Show_Graph:
    def __init__(self, data):
        self.data = data
        self.window = Tk()
        self.window.title("Graph")
        Button(self.window,text="Saving Graph",height=2,width=16,font=3,bg="#FFFFE0",command=self.Saving_Graph).grid(row=1,column=0)
        Button(self.window,text="Income Graph",height=2,width=16,font=3,bg="lightgreen",command=self.Income_Graph).grid(row=1,column=1)
        Button(self.window,text="Expenses Graph",height=2,width=16,font=3,bg="#FFCCCB",command=self.Expenses_Graph).grid(row=1,column=2)
        self.window.mainloop()

    def turtle_init(self,data):
        turtle.pensize(1)
        turtle.speed()
        turtle.clear()
        turtle.tracer(0,0)
        list_pos = []
        turtle.penup()
        turtle.goto(-300,-100)
        turtle.pendown()
        turtle.left(90)
        turtle.forward(400)
        turtle.goto(-300,-100)
        turtle.right(90)
        for i in list(data.keys()):
            turtle.forward(600/len(data))
            turtle.right(90)
            turtle.penup()
            turtle.forward(30)
            turtle.write(i,False,align="center")
            turtle.right(180)
            turtle.forward(30)
            turtle.right(90)
            turtle.pendown()
            pos = turtle.position()
            list_pos.append(pos)
        turtle.penup()
        return list_pos


    def find_max(self,index):
        list_y = []
        for i in self.data.values():
            list_y.append(i[index])
        return max(list_y) if max(list_y) != 0 else 1

    
    def Saving_Graph(self):
        list_pos = self.turtle_init(self.data)
        saving_data = Generate_table.find_saving(self)
        list_y = list(saving_data[0].values())
        scale_y = max(list_y)/200 if max(list_y) != 0 else 1/200
        for i,pos in enumerate(list_pos):
            if list_y[i]/scale_y >= -100 :
                turtle.goto(pos[0],list_y[i]/scale_y)
            else :
                turtle.goto(pos[0],-100)
            turtle.pendown()
        turtle.update()
        turtle.done()


    def Income_Graph(self):
        list_pos = self.turtle_init(self.data)
        scale_y = self.find_max(0)/200
        for i,pos in enumerate(list_pos):
            if self.data[i+1][0]/scale_y >= -100 :
                turtle.goto(pos[0],self.data[i+1][0]/scale_y)
            else :
                turtle.goto(pos[0],-100)
            turtle.pendown()
        turtle.update()
        turtle.done()


    def Expenses_Graph(self):
        list_pos = self.turtle_init(self.data)
        scale_y = self.find_max(1)/200
        for i,pos in enumerate(list_pos):
            if self.data[i+1][1]/scale_y >= -100 :
                turtle.goto(pos[0],self.data[i+1][1]/scale_y)
            else :
                turtle.goto(pos[0],-100)
            turtle.pendown()
        turtle.update()
        turtle.done()


class Main_Menu :
    def __init__(self) :
        main = Tk()
        main.title("Create&load")
        Label(main,text="Finance Calendar",height=2,font=10,bg="#333333",fg="white").pack(side = LEFT)
        Button(main,text="New",height=1,width=10,font=5,bg="lightgreen",command=self.new).pack(side = LEFT)
        Button(main,text="load",height=1,width=10,font=5,bg="#FFFFE0",command=self.save).pack(side = LEFT)
        main.mainloop()

    def save(self):
        filepath = filedialog.askopenfilename(filetypes=[('All Files', '*.*')], title="Load File")
        if filepath is None:
            print("\nFile not Load\n")
        else:
            file = open(filepath, "rb")
            data = pickle.load(file)
            file.close()
            print("\nFile has been loaded\n")
            self = Finance_Calendar(data[0],data[1],data[2])

    def new(self):
        self = Select_date()


x = Main_Menu()
