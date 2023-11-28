import turtle
turtle.pensize(1)
n = int(input("Enter the N : "))
dis = 100/n
for i in range(n):
    turtle.goto(0,-dis*i)
    turtle.pendown()
    for i in range(n):
        for i in range(4):
            turtle.forward(dis)
            turtle.right(90)
        turtle.forward(dis)
    turtle.penup()
turtle.done()