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

turtle.pensize(1)
turtle.speed(0)
turtle.tracer(0)
turtle.penup()
days = ["Su","Mo","Tu","We","Th","Fr","Sa"]
i = 0
#create table
while i < 12:
    if i < 4 : 
        turtle.goto(-500,300-(i*175))
    elif i < 8 : 
        turtle.goto(-250,300-((i-4)*175))
    else : 
        turtle.goto(0,300-((i-8)*175))
    turtle.pendown()
    obj = calendar.Calendar(firstweekday= 6)
    count = 0
    box(175,15)
    moverow()
    j = 0
    while j < (len(obj.monthdayscalendar(2022, i+1))+1)*7:
        box(25,15)
        count += 1
        if count%7 == 0:
            moverow()
        j += 1
    turtle.penup()
    i += 1

#Write number
i = 0
while i < 12:
    if i < 4 : 
        turtle.goto(-491,300-(i*175))
    elif i < 8 : 
        turtle.goto(-241,300-((i-4)*175))
    else : 
        turtle.goto(9,300-((i-8)*175))
    obj = calendar.Calendar( firstweekday= 6)
    count = 0
    turtle.write("Month#"+str(i+1))
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
    while j < len(obj.monthdayscalendar(2022, i+1))*7:
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
        j += 1
    i += 1
turtle.update()
turtle.done()