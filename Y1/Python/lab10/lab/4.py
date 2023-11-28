import turtle
class Histogram:
    def __init__(self,x) :
        self.listchar = set(x)
        self.listfreq = self.check_frequency(x,self.listchar)
        self.darw()

    def check_frequency(self,x,listchar):
        listfreq = []
        c = 0
        for i in listchar:
            for j in x :
                if i == j:
                    c += 1
            listfreq.append(c)
            c = 0
        return listfreq

    def darw(self):
        turtle.pensize(2)
        turtle.speed(3)
        turtle.penup()
        turtle.goto(-100,0)
        turtle.pendown()
        turtle.left(90)
        turtle.forward((max(self.listfreq)+2)*20)
        turtle.left(180)
        turtle.forward((max(self.listfreq)+2)*20)
        turtle.left(90)
        turtle.forward(30)
        for i in range(len(self.listchar)) :
            turtle.forward(20)
            turtle.right(90)
            turtle.penup()
            turtle.forward(20)
            turtle.write(list(self.listchar)[i],font=15)
            turtle.right(180)
            turtle.forward(20)
            turtle.pendown()
            for j in range(2) :
                turtle.forward(self.listfreq[i]*20)
                turtle.right(90)
                turtle.forward(20)
                turtle.right(90)
            turtle.right(90)
        turtle.forward(70)
        turtle.done()

Histogram([1,2,2,1,3,4,6,5,3,4,5,6,4,3,5,4,5,3,4,4,3,3,4,3,3,4,4,4])