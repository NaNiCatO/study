def longest_palin_subseq(s):
    memo = {}
    def opt(i, j):
        if (i, j) in memo:
            return memo[(i, j)]
        elif i > j:
            return 0
        elif i == j:
            return 1
        elif s[i] == s[j]:
            memo[(i, j)] = 2 + opt(i+1, j-1)
            return memo[(i, j)]
        else:
            memo[(i, j)] = max(opt(i+1, j), opt(i, j-1))
            return memo[(i, j)]
    return opt(0, len(s)-1)

#test cases
print(longest_palin_subseq("bbbab"))
print(longest_palin_subseq("cbbd"))
print(longest_palin_subseq("a"))
print(longest_palin_subseq("abc"))
print(longest_palin_subseq("gamenoon"))
