n1 = " "
n2 = " "
print("Pattern A")
for i in range(1,6) :
    n1 = str(n1) + " " + str(i)
    print(n1)
print()

print("Pattern B")
for x in range(1,6,-1) :
    r = 7
    r = r - x
    print(n2,end = str(r))

