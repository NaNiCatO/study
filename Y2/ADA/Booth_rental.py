

# flee = int(input())
# list_numbers = list(map(int, input().split()))

# memo = {}
# def rental_booth(flee, list_num):
#     if len(list_num) == 0:
#         return 0
#     elif len(list_num) == 1:
#         memo[(flee, tuple(list_num))] = list_num[0] - flee
#         return memo[(flee, tuple(list_num))]
#     else:
#         if (flee, tuple(list_num)) in memo:
#             return memo[(flee, tuple(list_num))]
#         else:

#             profit_from_f = (list_num[-1] - flee) + rental_booth(flee, list_num[:-1])
#             profit_from_s = (list_num[0] - flee) + rental_booth(flee, list_num[1:])
#             max_profit = max(profit_from_f, profit_from_s)
#             memo[(flee, tuple(list_num))] = max_profit
#             return memo[(flee, tuple(list_num))]

# result = rental_booth(flee, list_numbers)
# if result <= 0:
#     print("No")
# else:
#     print(result)


memo = {}
def test(flee, list_num):
    if (flee, tuple(list_num)) in memo:
        return memo[(flee, tuple(list_num))]
    elif len(list_num) == 0:
        return 0
    elif len(list_num) == 1:
        memo[(flee, tuple(list_num))] = list_num[0] - flee
        return memo[(flee, tuple(list_num))]
    else:
        profit_from_f = (list_num[-1] - flee) + test(flee, list_num[:-1])
        profit_from_s = (list_num[0] - flee) + test(flee, list_num[1:])
        memo[(flee, tuple(list_num))] = max(profit_from_f, profit_from_s)
        return memo[(flee, tuple(list_num))]
        

flee = 50
list_numbers = [54, 55, 40, 48, 51, 50, 56, 49, 54, 47]
list_num1 = [45, 50, 49]
test(flee, list_numbers)
# get max value from memo
result = 0
for key, value in memo.items():
    if value > result:
        result = value
print(result if result > 0 else "No")