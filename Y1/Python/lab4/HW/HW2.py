import turtle
r1 = input("Enter the first center of rectangles : ").split(",")
l1 = input("Enter the width,height : ").split(",")
r2 = input("Enter the second center of rectangles : ").split(",")
l2 = input("Enter the width,height : ").split(",")
sorty = [r1[1],r2[1]]
sortl = [l1[1],l2[1]]
difx, dify = abs(float(r1[0])-float(r2[0])),abs(float(r1[1])-float(r2[1]))
turtle.pensize(2)
turtle.penup()

#First rec
turtle.goto(float(r1[0])-(float(l1[0])/2),float(r1[1])-(float(l1[1])/2))
turtle.pendown()
for i in range(2):
    turtle.forward(float(l1[0]))
    turtle.left(90)
    turtle.forward(float(l1[1]))
    turtle.left(90)
turtle.penup()

#Second rec
turtle.goto(float(r2[0])-(float(l2[0])/2),float(r2[1])-(float(l2[1])/2))
turtle.pendown()
turtle.color("red")
for i in range(2):
    turtle.forward(float(l2[0]))
    turtle.left(90)
    turtle.forward(float(l2[1]))
    turtle.left(90)
turtle.penup()

turtle.color("black")
if r1 == r2 and l1 == l2 :
    turtle.goto(-100,float(min(sorty))-(float(min(sortl))+50))
    turtle.write("Overlap with each other",False,font=15)
elif difx <= abs(float(r1[0])) and dify <= abs(float(r1[1])) and (abs(float(l2[0]))/2) + difx <= (abs(float(l1[0]))/2) and (abs(float(l2[1]))/2) + dify <= (abs(float(l1[1]))/2):
    turtle.goto(-100,float(min(sorty))-(float(min(sortl))+50))
    turtle.write("Second rectangles is inside first rectangles",False,font=15)
elif difx <= abs(float(r2[0])) and dify <= abs(float(r2[1])) and (abs(float(l1[0]))/2) + difx <= (abs(float(l2[0]))/2) and (abs(float(l1[1]))/2) + dify <= (abs(float(l2[1]))/2):
    turtle.goto(-100,float(min(sorty))-(float(min(sortl))+50))
    turtle.write("First rectangles is inside second rectangles",False,font=15)
elif abs(float(r1[0])-float(r2[0])) < (float(l1[0])/2)+(float(l2[0])/2) and abs(float(r1[1])-float(r2[1])) < (float(l1[1])/2)+(float(l2[1])/2):
    turtle.goto(-100,float(min(sorty))-(float(min(sortl))+50))
    turtle.write("Overlap with the other",False,font=15)
else :
    turtle.goto(-100,float(min(sorty))-(float(min(sortl))+50))
    turtle.write("Rectangles didn't overlap with the other",False,font=15)
turtle.done()
