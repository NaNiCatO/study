import turtle

turtle.tracer(0)
#turtle.speed(5)
def cross(len,n):
    if n > 1 :
        for i in range(4):
            turtle.forward(len)
            cross(len/2,n-1)
            turtle.right(180)
            turtle.forward(len)
            turtle.left(90)
    elif n == 1:
        for i in range(4):
            turtle.forward(len)
            turtle.dot()
            turtle.right(180)
            turtle.forward(len)
            turtle.left(90)
    else:
        turtle.dot()


cross(100,5)
turtle.done()