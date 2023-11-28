import turtle
def draw_polygon(x = 0, y = 0, type = 4, size = 100):
    turtle.penup()
    turtle.goto(int(x),int(y))
    turtle.pendown()
    for i in range(int((type))):
        turtle.forward(int(size))
        turtle.right(360 / int(type))
    turtle.done()

turtle.pensize(1)
turtle.speed(1)

draw_polygon(0,0,None)