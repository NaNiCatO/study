def sum(x):
    s = 0
    for i in range(len(x)):
        s += int(x[i])
    return(s)

m = input("Enter the number : ")
print(sum(m))
