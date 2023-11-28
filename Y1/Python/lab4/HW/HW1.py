import turtle
p0 = input("Enter point p0 (x,y) : ").split(",")
p1 = input("Enter point p1 (x,y) : ").split(",")
p2 = input("Enter point p2 (x,y) : ").split(",")
c = [p0[1],p1[1]]
midx, midy = (float(p0[0])+float(p1[0]))/2, (float(p0[1])+float(p1[1]))/2
m = (float(p1[1])-float(p0[1]))/(float(p1[0])-float(p0[0]))
checky = (m*float(p2[0])) + float(min(c))
p = [midy-100,float(p2[1])-100]
turtle.pensize(2)
turtle.speed(1)
turtle.penup()
turtle.goto(float(p0[0]),float(p0[1]))
turtle.pendown()
turtle.write("p0",False)
turtle.goto(float(p1[0]),float(p1[1]))
turtle.write("p1",False)
turtle.penup()
turtle.goto(float(p2[0]),float(p2[1]))
turtle.pendown()
turtle.write("p2",False)
turtle.penup()
if checky == float(p2[1]):
    turtle.goto(midx,float(min(p)))
    turtle.pendown()
    turtle.write("p2 is on th line between p0 and p1",font=15)
elif float(p2[0]) > midx :
    turtle.goto(midx,float(min(p)))
    turtle.pendown()
    turtle.write("p2 is on the right side",font=15)
elif float(p2[0]) < midx :
    turtle.goto(midx,float(min(p)))
    turtle.pendown()
    turtle.write("p2 is on the left side",font=15)
elif float(p2[0]) == midx :
    turtle.goto(midx,float(min(p)))
    turtle.pendown()
    turtle.write("p2 is in the middle",font=15)
turtle.done()