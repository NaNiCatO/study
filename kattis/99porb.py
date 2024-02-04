x = int(input())
if x < 100:
    print("99")
elif x > 9999:
    print("9999")
else:
    remains = x%(100)

    lower = x - (remains + 1)

    upper = x + (100 - remains) - 1

    result = [lower,upper]
    dif_l = x - lower
    dif_u = upper - x
    dif_arr = [dif_l,dif_u]
    print(upper)
