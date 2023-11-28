def get_the_differrence(x,y):
    list_differnce = []
    for i in range(0, len(x)):
        if x[i] not in y:
            list_differnce.append(x[i])
    for i in range(0, len(y)):
        if y[i] not in x:
            list_differnce.append(y[i])
    print(list_differnce)



get_the_differrence([3,1,1,1,2,7],[4,1,1,2,2,5])