S = [0,3,7,5,1,4]
Y = 6
memo = {}



def check_recur(k,Y):
    if k == 0 :
        return Y == 0
    else:
        if (k,Y) in memo:
            return memo[(k,Y)]
        elif Y >= S[k]:
            memo[(k,Y)] = check_recur(k-1,Y-S[k-1]) or check_recur(k-1,Y)
            return memo[(k,Y)]
        else:
            memo[(k,Y)] = check_recur(k-1,Y)
            return memo[(k,Y)]
        
print(check_recur(5,Y))


arr = {}
def check(k,Y) :
    for i in range(k+1):
        for j in range(Y+1):
            if i == 0:
                arr[(i,j)] = j == 0
            elif j >= S[i]:
                arr[(i,j)] = arr[(i-1,j-S[i])] or arr[(i-1,j)]
            else:
                arr[(i,j)] = arr[(i-1,j)]
    return arr[(k-1,Y)]

print(check(5,Y))

def check_arr(k,Y):
    check_table = [[False for _ in range(Y+1)] for _ in range(k+1)]
    check_table[0][0] = True

    for i in range(1,k+1):
        for j in range(Y+1):
            if j >= S[i]:
                check_table[i][j] = check_table[i-1][j-S[i]] or check_table[i-1][j]
            else:
                check_table[i][j] = check_table[i-1][j]
    return check_table[k][Y]

print(check_arr(5,Y))

def check_arr_reduce(k,Y):
    check_table = [False for _ in range(Y+1)]
    check_table[0] = True

    for i in range(1,k+1):
        for j in range(Y,S[i]-1,-1):
            check_table[j] = check_table[j-S[i]] or check_table[j]
    return check_table[Y]

print(check_arr_reduce(5,Y))