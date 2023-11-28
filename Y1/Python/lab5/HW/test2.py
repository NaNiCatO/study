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
turtle.speed(1)
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
    
    while j < 7:
        box(25,15)
        j += 1
    moverow()
    for day in obj.itermonthdays(2022, i+1):
        box(25,15)
        count += 1
        if count%7 == 0:
            moverow()
    turtle.penup()
    i += 1
i = 0
#Write number
while i < 12:
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
    for j in days:
        turtle.write(str(j))
        turtle.forward(25)
    moverow()
    for day in obj.itermonthdays(2022, i+1):
        if day != 0:
            turtle.write(day)
        turtle.forward(25)
        count += 1
        if count%7 == 0:
            moverow()
        turtle.penup()
    i += 1
turtle.update()
turtle.done()