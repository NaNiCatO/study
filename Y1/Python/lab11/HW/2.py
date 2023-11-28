def composite(x,y):
    x_k = list(x.keys())
    x_v = list(x.values())
    y_k = list(y.keys())
    y_v = list(y.values())
    dict_xy = {}
    for i in range(len(x)):
        for j in range(len(y)):
            if x_v[i] == y_k[j]:
                dict_xy[x_k[i]] = y_v[j]
    return dict_xy

dict1 = {'a':'p','b':'r','c':'q','d':'p','e':'s'}
dict2 = {'p':'1','q':'2','r':'3'}

print(composite(dict1,dict2))