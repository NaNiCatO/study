s = set([1,2,3])
def power(x):
    ans = [set()]
    for element in x:
        for subset in ans:
            ans = ans + [subset | set([element])]
    return ans
    
print(power(s))