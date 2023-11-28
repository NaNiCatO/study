class Name :
    def __init__(self) :
        self.title = "" 
        self.first = ""
        self.last = ""

    def setName(self,t,f,l):
        self.title = t
        self.first = f
        self.last = l
    
    def getFullName(self):
        return "{0}. {1} {2}".format(self.title,self.first,self.last)

class Date :
    def __init__(self):
        self.day = 0
        self.month = 0
        self.year = 0

    def setDate(self,d,m,y):
        if 1 <= d <= 31 and 1 <= m <= 12 :
            self.day = d
            self.month = m
            self.year = y
        else :
            print("Wrong format")
    
    def getDate(self):
        return "{}/{}/{}".format(self.day,self.month,self.year)

    def getDate_BC(self):
        return"{}/{}/{}".format(self.day,self.month,self.year+543)

class Address:
    def __init__(self):
        self.houseNo = ""
        self.street = ""
        self.district = ""
        self.city = ""
        self.country = ""
        self.postcode = ""

    def setAddress(self,houseNo,street,district,city,country,postcode):
        self.houseNo = houseNo
        self.street = street
        self.district = district
        self.city = city
        self.country = country
        self.postcode = postcode

    def getAddress(self):
        return "{} {} {} {} {} {}".format(self.houseNo,self.street,self.district,self.city,self.country,self.postcode)

class Department:
    def __init__(self,des):
        self.description = des
        self.manager = ""
        self.employeelist = []

    def addEmployee(self,e):
        self.employeelist.append(e)
        e.Department = self

    def deleteEmployee(self,e):
        self.employeelist.remove(e)
        e.Department = None

    def setManager(self,e):
        if type(e) == PermEmployee and e in self.employeelist:
            self.manager = e

    def printInfo(self):
        print("Description : {0}\n {1}\n{2}".format(self.description,self.manager,self.employeelist))
    
class Person(Name,Date,Address):
    def __init__(self):
        super().__init__()

    def printInfo(self):
        super().getFullName()
        super().getDate()
        super().getAddress()

class Employee(Person):
    def __init__(self,startDate):
        super().__init__()
        self.startDate = startDate
        self.Department = Department

    def printInfo(self):
        super().printInfo()
        print("startDate : {}\ndepartment : {}".format(self.startDate,self.Department))

class TempEmployee(Employee):
    def __init__(self,w):
        self.wage = w
    
    def printInfo(self):
        super().printInfo()
        print("wage : {}".format(self.wage))

class PermEmployee(Employee):
    def __init__(self, s):
        self.salary = s

    def printInfo(self):
        super().printInfo()
        print("salary : {}".format(self.salary))



    