import turtle

t = turtle

t.right(90)
t.penup()
t.forward(100)
t.left(90)
t.pendown()
t.circle(100)
t.penup()
t.goto(0,0)
t.forward(100)
t.goto(0,0)
t.pendown()

def pie_chart(list):
    total = 0
    frq = []
    num_list = []
    for i in list:
        total += 1
        if not num_list:
            num_list.append(i)
            frq.append(1)
            
        else :
            found = False
            
            for x in range(len(num_list)) :
                if num_list[x] == i:
                    frq[x] += 1
                    found = True
                    break
            if not found:
                num_list.append(i)
                frq.append(1)
    print(num_list)
    print(frq)
    for i in range(len(frq)):
        t.right((frq[i]/total) * 360)
        t.forward(100)
        t.penup()
        t.goto(0,0)
        t.pendown()
            
pie_chart([3,1,3,3,2,3,3,2,3,2,4,3,3,3,3,4,3,4,3,3,3,4,3])
t.done()
