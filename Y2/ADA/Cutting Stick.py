def cutting(length, cuts):
    memo = {}

    def opt(l, r):
        if r - l == 1:
            return 0
        if (l, r) in memo:
            return memo[(l, r)]
        res = float("inf")
        for c in cuts:
            if l < c < r:
                res = min(res, r - l + opt(l, c) + opt(c, r))
        if res == float("inf"):
            res = 0
        memo[(l, r)] = res
        return res

    return opt(0, length)


length = int(input())
cuts = list(map(int, input().split()))
print(cutting(length, cuts))
    