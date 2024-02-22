# number picking
list_numbers = list(map(int, input().split()))

def picking_number(list_num):
    if len(list_num) == 0:
        return True
    else:
        return picking_numbers(list_num[1:], list_num[0]) or picking_numbers(list_num[:-1], list_num[-1])

def picking_numbers(list_num, picked_num):
    if len(list_num) == 0:
        return True
    else: 
        f_h = False
        s_h = False
        if abs(list_num[0] - picked_num) <= 9:
            f_h = picking_numbers(list_num[1:], list_num[0])
        if abs(list_num[-1] - picked_num) <= 9:
            s_h = picking_numbers(list_num[:-1], list_num[-1])
        return f_h or s_h



if picking_number(list_numbers):
    print("Yes")
else:  
    print("No")