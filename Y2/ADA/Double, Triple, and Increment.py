# Double, Triple, and Increment
memo = {}
def opt(value):
    if value in memo:
        return memo[value]
    elif value == 1:
        return 0

    min_value = opt(value-1)
    if value%3 == 0:
        return min(min_value, opt(value/3)) + 1
    elif value%2 == 0:
        memo[value] = min(min_value, opt(value/2)) + 1
        return memo[value]
    else:
        memo[value] = min_value + 1
        return memo[value]
    
def opt2(value):
    memo = [0 for _ in range(value+1)]
    for i in range(2, value+1):
        memo[i] = memo[i-1] + 1
        if i%2 == 0:
            memo[i] = min(memo[i], memo[i//2] + 1)
        if i%3 == 0:
            memo[i] = min(memo[i], memo[i//3] + 1)
    return memo[value]

user_input = input()

# print(opt(int(user_input)))
print(opt2(int(user_input)))