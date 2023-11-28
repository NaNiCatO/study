def product(*s):
    ans = []
    for i in range(len(s)):
        if i == 0:
            ans = [(j,) for j in s[i]]
        else:
            ans = [x + (y,) for x in ans for y in s[i]]
            
    return ans

s1 = set([1,2,3])
s2 = set(['p','q'])
s3 = set(['a','b','c'])

print(product(s1,s2))
print(product(s1, s2, s3))
print(product(s1))