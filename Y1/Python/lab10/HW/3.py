def my_union(x,y):
    ans = []
    ans = ans + x
    for i in range(len(x)):
        for j in y:
            if j not in ans :
                ans.append(j)
    
    return ans

def my_intersection(x,y):
    ans = []
    for j in y:
        if j in x :
            ans.append(j)
    return ans

def my_difference(x,y) :
    ans = []
    for j in x:
        if j not in y :
            ans.append(j)
    return ans


list1 = [3, 1, 2, 7]
list2 = [4, 1, 2, 5]

list3 = my_union(list1,list2)
print(list3)
list4 = my_intersection(list1,list2)
print(list4)
list5 = my_difference(list1,list2) 
print(list5)
