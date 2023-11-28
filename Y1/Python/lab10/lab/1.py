def name_list():
    listname = []
    ans = "x"
    c = 0
    while ans != "" :
        c += 1
        ans = input("Enter name {} :".format(c))
        listname.append(ans)
    listname.pop()
    print(listname)

name_list()