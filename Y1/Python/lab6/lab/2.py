import turtle
turtle.tracer(0)
def drawbox(l):
    for i in range(4):
        turtle.forward(l/2)
        turtle.left(90)
        turtle.forward(l/2)
        turtle.left(90)
        turtle.forward(l/2)
        turtle.left(90)
        turtle.forward(l/2)
def bigbox(b):
    c = b
    for i in range(4):
        drawbox(b)
        b += c

size = float(input("Enter the size : "))
bigbox(size)
turtle.update()
turtle.done()