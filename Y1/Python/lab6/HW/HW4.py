def hundred(num):
    hun = number(num)+" hundred"
    return hun

def ty(num):
    list = ["twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"]
    return list[num-2]

def teen(num):
    list = ["ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"]
    return list[num-10]

def number(num):
    list = ["one","two","three","four","five","six","seven","eight","nine"]
    return list[num-1]

def calculate(num):
    if num >= 0 and num <= 999:
        if num == 0:
            print("zero")
        else :
            if num//100 != 0:
                h = num//100
                print(hundred(h),end=" and ")
            if (num%100)//10 != 0:
                t = (num%100)//10
                if num%10 != 0 and t >= 2:
                    print(ty(t),end="-")
                    print(number(num%10))
                elif num%10 == 0 and t >= 2:
                    print(ty(t))
                else :
                    print(teen(num%100))
            else :
                print(number(num%10))
    else :
        print("I don't know.")

x = int(input("Enter a number : "))
calculate(x)