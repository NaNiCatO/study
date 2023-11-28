def remove_the_thirds(x):
    for i in range(1,(len(x)//3)+1):
        c = 2*i
        x.pop(c)
    

x = [1,2,3,4,5,6,7,8,9]
remove_the_thirds(x)
print(x)