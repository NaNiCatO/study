import turtle
rainbow = ["red", "orange", "yellow", "green", "blue", "indigo", "violet", "white"]
x, y, r, c = 200, 0, 200, 0
turtle.pensize(2)
turtle.speed(15)

#house
turtle.penup()
turtle.goto(-x+10,50)
turtle.pendown()
turtle.fillcolor("#ffa631")
turtle.begin_fill()
for i in range(2):
    turtle.forward((x-10)*2)
    turtle.right(90)
    turtle.forward((x-10)*1.5)
    turtle.right(90)
turtle.penup() 
turtle.goto(225,-235)
turtle.pendown()
turtle.right(180)
turtle.end_fill()
for i in range(12):
    turtle.right(90)
    turtle.fillcolor("white")
    turtle.begin_fill()
    turtle.circle(30)
    turtle.end_fill()
    turtle.penup()
    turtle.left(90)
    turtle.forward(35)
    turtle.pendown()

#raindow
turtle.penup()
turtle.goto(-x,-y)
turtle.pensize(3)
turtle.pendown()
turtle.goto(x,y)
turtle.pensize(1)
turtle.right(90)
for i in rainbow :
    turtle.fillcolor(i)
    turtle.penup()
    turtle.goto(x,y)
    turtle.pendown()
    turtle.begin_fill()
    turtle.circle(r,180)
    turtle.end_fill()
    turtle.left(180)
    x, r = x-12, r-12

#door
turtle.color("black")
turtle.pensize(2)
turtle.speed(1)
turtle.penup()
turtle.goto(-25,-235)
turtle.pendown()
turtle.fillcolor("black")
turtle.begin_fill()
for i in range(2):
    turtle.forward(75)
    turtle.right(90)
    turtle.forward(50)
    turtle.right(90)
turtle.end_fill()
turtle.done()


