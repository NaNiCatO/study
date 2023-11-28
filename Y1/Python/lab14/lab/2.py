def list_reverse(l):
    if l == []: 
        return []
    return [l[-1]] + list_reverse(l[:-1])

print(list_reverse([1,2,3]))
