dict = {'a':'1','b':'2','c':'1','d':'3','e':'1','f':'2'}
def inverse(x):
    temp = {}
    for key, value in dict.items():
        if value not in temp:
            temp[value] = set(key)
        else:
            temp[value].add(key)
    print(temp)

inverse(dict)
    