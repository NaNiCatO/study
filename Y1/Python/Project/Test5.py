x = ["3","+","3","-","3","+","4"]
a = ["3","-4","+","12"]
def format_number(list):
    integer = list[::2]
    op = list[1::2]
    sum = int(integer.pop(0))
    print(integer,op,sum)
    
    for i in range(len(integer)):
        print(integer[i],op[i])
        if op[i] == "+" :
            sum += int(integer[i])
        elif op[i] == "-" :
            sum -= int(integer[i])
        elif op[i] == "/" :
            sum /= int(integer[i])
        elif op[i] == "*" :
            sum *= int(integer[i])
        else :
            print("Incorrect_format")
    print(sum)
    return sum

ans = format_number(a)
print(ans)