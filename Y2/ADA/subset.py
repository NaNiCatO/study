# S = [0,3,7,5,1,4]
# Y = 6
# memo = {}



# def check_recur(k,Y):
#     if k == 0 :
#         return Y == 0
#     else:
#         if (k,Y) in memo:
#             return memo[(k,Y)]
#         elif Y >= S[k]:
#             memo[(k,Y)] = check_recur(k-1,Y-S[k-1]) or check_recur(k-1,Y)
#             return memo[(k,Y)]
#         else:
#             memo[(k,Y)] = check_recur(k-1,Y)
#             return memo[(k,Y)]
        
# print(check_recur(5,Y))


# arr = {}
# def check(k,Y) :
#     for i in range(k+1):
#         for j in range(Y+1):
#             if i == 0:
#                 arr[(i,j)] = j == 0
#             elif j >= S[i]:
#                 arr[(i,j)] = arr[(i-1,j-S[i])] or arr[(i-1,j)]
#             else:
#                 arr[(i,j)] = arr[(i-1,j)]
#     return arr[(k-1,Y)]

# print(check(5,Y))

# def check_arr(k,Y):
#     check_table = [[False for _ in range(Y+1)] for _ in range(k+1)]
#     check_table[0][0] = True

#     for i in range(1,k+1):
#         for j in range(Y+1):
#             if j >= S[i]:
#                 check_table[i][j] = check_table[i-1][j-S[i]] or check_table[i-1][j]
#             else:
#                 check_table[i][j] = check_table[i-1][j]
#     return check_table[k][Y]

# print(check_arr(5,Y))

# def check_arr_reduce(length, target):
#     check_table = [False for _ in range(target+1)]
#     check_table[0] = True

#     for i in range(1, length+1):
#         for j in range(target, numbers[i]-1, -1):
#             check_table[j] = check_table[j-numbers[i]] or check_table[j]
#     return check_table[target]



# subset
def opt(l, t):
    if l == 0 :
        return t == 0 or numbers[l] == t
    else:
        if t >= numbers[l]:
            print(l, t-numbers[l])
            return opt(l-1, t-numbers[l]) or opt(l-1, t)
        else:
            return opt(l-1, t)
            
    

numbers = list(map(int, input().split()))
# numbers.insert(0, 0)
sum = int(input())
# print(check_arr_reduce(len(numbers)-1, sum))
print(opt(len(numbers)-1, sum))