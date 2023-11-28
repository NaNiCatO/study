import turtle
class Rectangle :
    def __init__(self,x,y,width,height):
        self.x = x
        self.y = y
        self.width = width
        self.height = height
    
    def getArea(self):
        area = self.width*self.height
        return area

    def getPerimeter(self):
        l = (self.width*2) + (self.height*2)
        return l
    
    def move(self,newX,newY):
        self.x = newX
        self.y = newY
    
    def intersect(self,rec):
        newrec = Rectangle(0,0,0,0)
        if (self.x >= rec.x) and  (rec.x + rec.width >= self.x) :
            newrec.x = self.xcoor
            if (self.x + self.width) < (rec.x + rec.width):
                newrec.width = self.width
            else :
                newrec.width = rec.width - (self.x - rec.x) 

        if (rec.x >= self.x) and (self.x + self.width >= rec.x) :
            newrec.x = rec.x
            if (self.x + self.width) > (rec.x + rec.width):
                newrec.width = rec.width
            else :
                newrec.width = self.width - (rec.x - self.x)


        if (self.y >= rec.y) and (self.y - rec.height <= rec.y) :
            newrec.y = rec.y
            if (self.y - self.height) < (rec.y - rec.height):
                newrec.height = rec.height
            else : 
                newrec.height = self.height - (self.y - rec.y) 

        if (rec.y >= self.y) and (rec.y - rec.height <= self.y) :
            newrec.y = self.y 
            if (self.y - self.height) > (rec.y - rec.height):
                newrec.height = self.height
            else : 
                newrec.height = rec.height - (rec.y - self.y) 
        return newrec
    def draw(self):
        turtle.pensize(1)
        turtle.speed(3)
        turtle.penup()
        turtle.goto(self.x,self.y)
        turtle.pendown()
        for i in range(2):
            turtle.forward(self.width)
            turtle.right(90)
            turtle.forward(self.height)
            turtle.right(90)

a = Rectangle(0,0,100,100)
b = Rectangle(50,-60,75,75)
a.draw()
b.draw()
c = a.intersect(b)
c.draw()
turtle.done()