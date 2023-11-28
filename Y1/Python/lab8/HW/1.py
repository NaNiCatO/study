x = 1
while x != 0:
    x = int(input("Enter the number : "))
    remain = x
    strbi = ""
    sum = 0
    if x < 0 :
        print("It is negative")
        break
    else :
        print("binary\tinteger")
        while remain != 0:
            bi = remain%2
            remain = remain//2
            strbi = str(bi) + strbi
        for i in range(len(strbi)):
            sum = sum + (2**i)*int(strbi[-(i+1)])
        print("{0}\t{1}".format(strbi if x != 0 else "0",sum))
