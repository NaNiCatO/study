import turtle
x = float(input("Enter the length of the star : "))
turtle.pensize(1)
turtle.speed(1)
for i in range(5):
    turtle.forward(x)
    turtle.right(144)
turtle.done()