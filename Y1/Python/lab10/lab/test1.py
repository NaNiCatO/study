def merge(list1,list2):
    c = [len(list1),len(list2)]
    ans = ""
    for i in range(min(c)):
        if list1[i] < list2[i] :
            ans = ans + " " + list1[i] + " " + list2[i]
        else :
            ans = ans + " " + list2[i] + " " + list1[i]
    ans = (ans.split(" ")).pop(0)
    if len(list1) > len(list2) :
        ans
    return ans

x = input("Enter list1 : ").split(" ")
y = input("Enter list2 : ").split(" ")
z = merge(x,y)
print(z)