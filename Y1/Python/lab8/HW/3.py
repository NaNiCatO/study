import turtle
def check_char(x):
    c = 0
    listchar = []
    for i in x:
        for j in listchar :
            if i == j:
                c += 1
        if c == 0 :
            listchar.append(i)
        c = 0
    return listchar

def check_frequency(x,listchar):
    listfreq = []
    c = 0
    for i in listchar:
        for j in x :
            if i == j:
                c += 1
        listfreq.append(c)
        c = 0
    return listfreq

text = str(input("Enter some text : "))
listchar = check_char(text)
listfreq = check_frequency(text,listchar)

turtle.pensize(2)
turtle.speed(3)
turtle.penup()
turtle.goto(-100,0)
turtle.pendown()
turtle.left(90)
turtle.forward((max(listfreq)+2)*20)
turtle.left(180)
turtle.forward((max(listfreq)+2)*20)
turtle.left(90)
for i in range(len(listchar)) :
    turtle.forward(50)
    turtle.right(90)
    turtle.penup()
    turtle.forward(20)
    turtle.write(listchar[i],font=15)
    turtle.right(180)
    turtle.forward(20)
    turtle.pendown()
    for j in range(2) :
        turtle.forward(listfreq[i]*20)
        turtle.right(90)
        turtle.forward(20)
        turtle.right(90)
    turtle.right(90)
turtle.forward(70)
turtle.done()