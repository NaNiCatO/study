import turtle

t = turtle.Turtle()
t.speed(0)

#draw box (start at (-900,450))
#t.penup()
t.penup()
t.goto(-900,450)
turtle.tracer(0)

y = 1
i = 1
j = 1
h = 0
x = 0

while y < 4 :
    i = 1
    while i < 5 :
        t.pendown()
        t.right(90)
        t.forward(30)
        t.back(30)
        t.left(90)
        t.forward (210)
        t.right(90)
        t.forward(60)
        t.right(90)
        j = 1
        while j < 7 :
            h = 0
            while h < 7 :
                x = 0
                while x < 4 :
                    t.forward(30)
                    t.right(90)
                    x += 1
                t.forward(30)
                h += 1
            t.penup()
            t.goto(-690 + (240 * (i-1)),390 - (j*30) - (210*(y-1)))
            t.pendown()
            j += 1
        t. penup()
        t.goto(-900 + (240 * i),450 - (210*(y-1)))
        t.right(180)
        t.pendown()
        i += 1
    t.penup ()
    t.goto(-900,240 - (210*(y-1)))
    t.pendown()
    y += 1

monthrow = 0
row = 0
month = 0

while row < 3 : 
    t.penup()
    t.goto(-900 , 420 - (row * 210))
    monthrow = 0
    while monthrow < 4 :
        month += 1
        #t.pendown()
        t.write("     Month # " + str(month))
        t.penup()
        t.forward(240)
        monthrow += 1
    row += 1

k = 0
month = 0
i = 0

while month < 12 and i < 3 :
    while k < 4 :
        month += 1
        if (month == 1) :
            count = 6  
        if (month == 1) or  (month == 3) or(month == 5) or(month == 7) or(month == 8) or(month == 12) or(month == 10):
            inmonth = 31
        elif (month == 2) :
            inmonth = 28
        else :
            inmonth = 30
        date = 0
        t.goto(-900 + (240 * k) + (30 * count),390 - (210 * i))
        while date < inmonth :
            date += 1
            count += 1
            t.penup()
            t.write("   " + str(date))
            t.forward(30)
            if (count % 7 == 0) :
                t.back(210)
                t.right(90)
                t.forward(30)
                t.left(90)
                count = 0
        k += 1
    k = 0
    i += 1

turtle.done()