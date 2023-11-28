s = 0
for i in range(5) :
    x = int(input("Enter an integer : "))
    if x < 0 :
        type = "neg"
        if i < 1 :
            oldtype = "neg"
    elif x >= 0 :
        type = "pos"
        if i < 1 :
            oldtype = "pos"
    
    if x < 0 and type == oldtype:
        s = s + x
        print("Current sum : ",s)
        oldtype = "neg"
    elif x >= 0 and type == oldtype:
        s = s + x
        print("Current sum : ",s)
        oldtype = "pos"
    elif x < 0 and type != oldtype:
        s = 0
        s = s + x
        print("Current sum : ",s)
        oldtype = "neg"
    elif x >= 0 and type != oldtype:
        s = 0
        s = s + x
        print("Current sum : ",s)
        oldtype = "pos"