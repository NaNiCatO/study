def gcd(x,y):
    a = max(x,y)
    b = min(x,y)
    if a % b == 0:
        return b
    else :
        temp = a % b
        a = b
        b = temp
        return gcd(a,b)

print(gcd(600,136))