def print_table(list):
    for i in range(len(list)):
        for j in range(len(list[0])):
            print(list[i][j],end="\t")
        print()

print_table([["x","Y"],[0,0],[10,10],[200,200]])
print_table([["ID","Name","Surname"],["001","Guido","vsn Rossum"],["002","Donald","Knuth"],["003","Gordon","Moore"]])