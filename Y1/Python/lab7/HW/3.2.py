import turtle
class Rectangle :
    def __init__(self,x,y,radius):
        self.x = x
        self.y = y
        self.radius = radius
    
    def getArea(self):
        area = (22/7)*(self.radius*self.radius)
        return area

    def getPerimeter(self):
        l = 2*(22/7)*self.radius
        return l
    
    def move(self,newX,newY):
        self.x = newX
        self.y = newY

    def draw(self):
        turtle.pensize(1)
        turtle.speed(3)
        turtle.penup()
        turtle.goto(self.x,self.y)
        turtle.pendown()
        turtle.circle(self.radius)

