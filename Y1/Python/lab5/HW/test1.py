import turtle
import calendar
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
turtle.speed(0)
days = ["Su","Mo","Tu","We","Th","Fr","Sa"]
i = 0

while i < 6:
    if i < 4 : 
        turtle.goto(-491,300-(i*175))
    elif i < 8 : 
        turtle.goto(-241,300-((i-4)*175))
    else : 
        turtle.goto(9,300-((i-8)*175))
    obj = calendar.Calendar( firstweekday= 6)
    count = 0
    turtle.write("Month#"+str(i))
    turtle.forward(175)
    moverow()
    turtle.penup()
    j = 0
    while j < len(days):
        turtle.write(str(days[j]))
        turtle.forward(25)
        j += 1
    moverow()
    j, w, d = 0, 0, 0
    turtle.write("======"+str(i)+"======")
    while j < len(obj.monthdayscalendar(2022, i+1)):
        if obj.monthdayscalendar(2022, i+1)[w][d] != 0:
            turtle.write(str(obj.monthdayscalendar(2022, i+1)[w][d]))
        turtle.forward(25)
        d += 1
        count += 1
        if count%7 == 0:
            moverow()
            w += 1
            if w == len(obj.monthdayscalendar(2022, i+1)) : w = 0
            d = 0
        turtle.penup()
    i += 1
