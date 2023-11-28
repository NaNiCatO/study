n = str(input("Enter the first 9 digits of an ISBN-10 as a string : "))
d10 = ((int(n[0])*1)+(int(n[1])*2)+(int(n[2])*3)+(int(n[3])*4)+(int(n[4])*5)+(int(n[5])*6)+(int(n[6])*7)+(int(n[7])*8)+(int(n[8])*9))%11
if d10 == 10 :
    d10 = "X"
print("Your ISBN-10 number is",n+str(d10))