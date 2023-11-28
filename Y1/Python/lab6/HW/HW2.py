import calendar
import turtle
def moverow():
    turtle.penup()
    turtle.right(90)
    turtle.forward(15)
    turtle.right(90)
    turtle.forward(175)
    turtle.right(180)
    turtle.pendown()

def box(w,h):
    for i in range(2):
            turtle.forward(w)
            turtle.left(90)
            turtle.forward(h)
            turtle.left(90)
    turtle.forward(w)

def calendar_of_2022(m):
    list = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]
    count = 0
    turtle.write("\t"+list[m-1]+" 2022",False)
    box(175,15)
    moverow()
    month = calendar.Calendar()
    for i in month.itermonthdays(2022, m):
        if i == 0 : i = " "
        turtle.write("   "+str(i),False)
        box(25,15)
        count += 1
        if count%7 == 0:
            moverow()

turtle.pensize(1)
turtle.speed(0)
calendar_of_2022(9)
turtle.done()