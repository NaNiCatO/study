import turtle

from random import randint

def pie_chart(list_num):
    turtle.pensize(1)
    turtle.speed(1)
    turtle.penup()
    turtle.goto(0, -100)
    turtle.pendown()
    turtle.colormode(255)
    radius = 100
    freq = {}
    sum = 0
    for i in list_num :
        try :
            freq[i] += 1
        except :
            freq[i] = 1
    print(freq)
    
    for i in freq.values():
        sum += i
    print(sum)

    for i in freq.values():
        turtle.color(randint(0, 255),
          randint(0, 255),
          randint(0, 255))
        turtle.begin_fill()
        turtle.circle(radius, i*360/sum)
        position = turtle.position()
        turtle.goto(0, 0)
        turtle.end_fill()
        turtle.setposition(position)
    turtle.done()

pie_chart([3,1,3,3,2,3,3,2,3,2,4,3,3,3,3,4,3,4,3,3,3,4,3])