#longest increasing subsequence
memo = {}
def opt(k):
    if k in memo:
        return memo[k]
    elif k == 0:
        return 1
    max_len = 0
    for i in range(k):
        if arr[i] <= arr[k]:
            result = opt(i)
            if max_len < result:
                max_len = result
    memo[k] = max_len + 1
    return memo[k]

def lis(p):
    maxLen = 0
    for k in range(len(p)):
        result = opt(k)
        if result > maxLen:
            maxLen = result
    return maxLen

arr = list(map(int, input().split()))

print(lis(arr))
