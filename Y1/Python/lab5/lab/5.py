n = int(input("Enter the number of lines : "))
if n%2 == 0:
    x = []
    j = -1
    for i in range(int(n/2)):
        xnew = 2**i
        x.insert(0,xnew)
        for j in range(i+1):
            print(x[j], end=' ')
        print()

    for i in range(int(n/2)):
        for j in range(len(x)):
            print(x[j], end=' ')
        print()
        x.pop(0)
else:
    x = []
    j = -1
    for i in range(int(n/2)+1):
        xnew = 2**i
        x.insert(0,xnew)
        for j in range(i+1):
            print(x[j], end=' ')
        print()

    for i in range(int(n/2)):
        x.pop(0)
        for j in range(len(x)):
            print(x[j], end=' ')
        print()


