import turtle
color = ["blue","black","red","yellow","green"]
r = float(input("Enter the radius of the ring : "))
turtle.pensize(5)
turtle.speed(3)
for i in color[0:3]:
    turtle.color(i)
    turtle.circle(r)
    turtle.penup()
    turtle.forward(r*2+15)
    turtle.pendown()
turtle.penup()
turtle.goto(r/9,0-r/9)
for i in color[3:5]:
    turtle.color(i)
    turtle.right(90)
    turtle.pendown()
    turtle.circle(r)
    turtle.penup()
    turtle.left(90)
    turtle.forward(r*2+15)
turtle.done()

