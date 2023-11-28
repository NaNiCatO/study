import turtle
import abc
turtle.pensize(1)
turtle.speed(0)
class Char(abc.ABC):
    @abc.abstractclassmethod
    def draw(self):
        pass

    @abc.abstractclassmethod
    def getWidth(self):
        pass

class Char0(Char):
    def draw(self,x,y):
        turtle.penup()
        turtle.goto(x,y)
        turtle.pendown()
        turtle.write("0")

    def getWidth(self):
        return self.width

class Char1(Char):
    def draw(self,x,y):
        turtle.penup()
        turtle.goto(x,y)
        turtle.pendown()
        turtle.write("1")

    def getWidth(self):
        return self.width

class Char2(Char):
    def draw(self,x,y):
        turtle.penup()
        turtle.goto(x,y)
        turtle.pendown()
        turtle.write("2")

    def getWidth(self):
        return self.width

class Char3(Char):
    def draw(self,x,y):
        turtle.penup()
        turtle.goto(x,y)
        turtle.pendown()
        turtle.write("3")

    def getWidth(self):
        return self.width

class Char4(Char):
    def draw(self,x,y):
        turtle.penup()
        turtle.goto(x,y)
        turtle.pendown()
        turtle.write("4")

    def getWidth(self):
        return self.width

class Char5(Char):
    def draw(self,x,y):
        turtle.penup()
        turtle.goto(x,y)
        turtle.pendown()
        turtle.write("5")

    def getWidth(self):
        return self.width

class Char6(Char):
    def draw(self,x,y):
        turtle.penup()
        turtle.goto(x,y)
        turtle.pendown()
        turtle.write("6")

    def getWidth(self):
        return self.width

class Char7(Char):
    def draw(self,x,y):
        turtle.penup()
        turtle.goto(x,y)
        turtle.pendown()
        turtle.write("7")

    def getWidth(self):
        return self.width

class Char8(Char):
    def draw(self,x,y):
        turtle.penup()
        turtle.goto(x,y)
        turtle.pendown()
        turtle.write("8")

    def getWidth(self):
        return self.width

class Char9(Char):
    def draw(self,x,y):
        turtle.penup()
        turtle.goto(x,y)
        turtle.pendown()
        turtle.write("9")

    def getWidth(self):
        return self.width

class Char10(Char):
    def draw(self,x,y):
        turtle.penup()
        turtle.goto(x,y)
        turtle.pendown()
        turtle.write("10")

    def getWidth(self):
        return self.width

dict_char = {"0" : Char0 ,"1" : Char1 ,"2" : Char2 ,"3" : Char3 ,"4" : Char4 ,"5" : Char5 ,"6" : Char6 ,"7" : Char7 ,"8" : Char8 ,"9" : Char9}

def drawNum(x):
    id = input("id : ")
    _x = float(input("x : "))
    _y = float(input("y : "))
    dict_char[x].draw(id,_x,_y)

x = input("Enter number : ")
drawNum(x)
turtle.done()