import turtle
turtle.pensize()
turtle.speed(0)

class Point:
    def __init__(self,x,y):
        self.x = x
        self.y = y

    def draw(self):
        turtle.penup()
        turtle.goto(self.x,self.y-2)
        turtle.pendown()
        turtle.fillcolor("black")
        turtle.begin_fill()
        turtle.circle(2)
        turtle.end_fill()
        turtle.pendown()


class Rectangle2D:
    def __init__(self,x,y,w,h):
        self.x = x
        self.y = y
        self.width = w
        self.height = h

    def draw(self):  
        turtle.penup()
        turtle.goto(self.x,self.y)
        turtle.forward(self.height/2)
        turtle.right(90)
        turtle.forward(self.width/2)
        turtle.pendown()
        for i in range(2):
            turtle.right(90)
            turtle.forward(self.height)
            turtle.right(90)
            turtle.forward(self.width)

def getRectangle(points):
    listx = []
    listy = []
    for i in points:
        listx.append(i.x)
        listy.append(i.y)
    x = (max(listx)+min(listx))/2
    y = (max(listy)+min(listy))/2
    w = max(listx)-min(listx)
    h = max(listy)-min(listy)
    return Rectangle2D(x,y,w,h)


p = str(input("Enter the point : "))
listp = p.split()
list_point = []
for i in range(0,len(listp),2):
    list_point.append(Point(float(listp[i]),float(listp[i+1])))

list_point.append(getRectangle(list_point))
print("Your rectangle center is at ({},{}) and it has the width of {} and height of {}".format(list_point[-1].x,list_point[-1].y,list_point[-1].width,list_point[-1].height))
for i in list_point:
    i.draw()

turtle.done()