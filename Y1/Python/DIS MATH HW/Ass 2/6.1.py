def gcd(x,y):
    a = max(x,y)
    b = min(x,y)
    while True :
        if a % b == 0:
            return b
        else :
            temp = a % b
            a = b
            b = temp

print(gcd(600,136))