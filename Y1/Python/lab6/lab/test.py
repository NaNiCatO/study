import turtle
def draw_polygon(x = 0, y = 0, type = 4, size = 100):
    turtle.penup()
    turtle.goto(-(size/2),y)
    turtle.pendown()
    for i in range(type):
        turtle.forward(size)
        turtle.right(360 / type)
    turtle.done()

turtle.pensize(1)
turtle.speed(3)
input = input("Darw polygon : ").split(",")
draw_polygon(int(input[0]), int(input[1]), int(input[2]), int(input[3]))
turtle.done()