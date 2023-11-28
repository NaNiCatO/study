def list_member(x,list_num):
    if list_num == []:
        return False
    elif x == list_num[0]:
        return True
    else :
        return list_member(x,list_num[1:])


print(list_member(2, [1,2,3]))
