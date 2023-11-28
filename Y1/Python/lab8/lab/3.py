short = input("Enter short :")
long = input("Enter long :")
x = 0
c = 0
if short != "" :
    while x < len(long) :
        if long[x] == short[c]:
            c = c + 1
        elif long[x] != short[c]:
            c = 0
        else :
            print(x)
        x = x + 1
        if c == len(short):
            break
    if c == len(short):
        print("True")
    else :
        print("False")
print("True")