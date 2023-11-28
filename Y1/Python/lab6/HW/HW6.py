def reverse(num):
    origin = num
    ans = 0
    for i in range(len(str(num))):
        lastnum = origin%10
        ans = (ans*10) + lastnum
        origin = origin//10
    return ans

print(reverse(1234))