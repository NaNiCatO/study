import abc
import turtle
turtle.pensize(1)
turtle.speed(0)
class TwoDshape:
    @abc.abstractmethod
    def __init__(self):
        pass
    @abc.abstractmethod
    def draw(self):
        pass


class Line(TwoDshape):
    def __init__(self,sX,sY,eX,eY):
        self.sX = sX
        self.sY = sY
        self.eX = eX
        self.eY = eY

    def draw(self):
        turtle.penup()
        turtle.goto(self.sX,self.sY)
        turtle.pendown()
        turtle.goto(self.eX,self.eY)
        

class Rectangle(TwoDshape):
    def __init__(self,x,y,w,h):
        self.x = x
        self.y = y
        self.wide = w
        self.height = h

    def draw(self):
        turtle.penup()
        turtle.goto(self.x,self.y)
        turtle.pendown()
        for i in range(2):
            turtle.forward(self.wide)
            turtle.right(90)
            turtle.forward(self.height)
            turtle.right(90)

class Circle(TwoDshape):
    def __init__(self,x,y,r):
        self.x = x
        self.y = y
        self.radius = r

    def draw(self):
        turtle.penup()
        turtle.goto(self.x,self.y)
        turtle.pendown()
        turtle.circle(self.radius)

class Square(TwoDshape):
    def __init__(self,x,y,w):
        self.x = x
        self.y = y
        self.wide = w

    def draw(self):
        turtle.penup()
        turtle.goto(self.x,self.y)
        turtle.pendown()
        for i in range(4):
            turtle.forward(self.wide)
            turtle.right(90)
