import math
import turtle

x1, y1 = list(input("Enter the point1 \"x, y\" : ").split(", "))
x2, y2 = list(input("Enter the point2 \"x, y\" : ").split(", "))
x3, y3 = list(input("Enter the point3 \"x, y\" : ").split(", "))
a = math.sqrt((int(x2) - int(x1))**2 + (int(y2) - int(y1))**2)
b = math.sqrt((int(x3) - int(x2))**2 + (int(y3) - int(y2))**2)
c = math.sqrt((int(x3) - int(x1))**2 + (int(y3) - int(y1))**2)
s = (a+b+c)/2
area = math.sqrt(s*(s-a)*(s-b)*(s-c))
turtle.pensize(1)
turtle.speed(1)
turtle.penup()
turtle.goto(int(x1),int(y1))
turtle.pendown()
turtle.goto(int(x2),int(y2))
turtle.goto(int(x3),int(y3))
turtle.goto(int(x1),int(y1))

turtle.penup()
y = [y1, y2, y3]
x = [x1, x2, x3]
tx = (int(max(x))-int(min(x)))/2
ty = int(min(y)) - 50
turtle.goto(-tx,ty)
turtle.pendown()
turtle.write("Area below the triangle is " + str(area), True)
turtle.done()