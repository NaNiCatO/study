import turtle
turtle.pensize(1)
n = int(input("Enter the N : "))
dis = 100/n
c = 0
for i in range(n):
    turtle.goto(0,-dis*i)
    turtle.pendown()
    for i in range(n):
        c += 1
        if c%2 != 0:
            turtle.fillcolor("black")
            turtle.begin_fill()    
        for i in range(4):
            turtle.forward(dis)
            turtle.right(90)
        turtle.end_fill()
        turtle.forward(dis)
    turtle.penup()
turtle.done()