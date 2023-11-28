def isAnagagram(x,y):
    if len(x) == len(y):
        for i in x :
            if i not in y:
                return False
        return True
    else :
        return False

print(isAnagagram("silent","listen"))