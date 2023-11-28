def is_subset(x,y):
    l = []
    for i in x:
        if i not in y:
            l.append(False)
        else :
            l.append(True)
    if False in l :
        return False
    else:
        return True


sup = set([1,2,3,4])
sub = set([1,2,4])
print(is_subset(sub,sup))
sub = set([1,2,5]) 
print(is_subset(sub,sup))