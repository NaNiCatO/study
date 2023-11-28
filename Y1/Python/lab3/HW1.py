name = input("Enter employee's name : ")
work = float(input("Enter number of hours worked in a week : "))
pay = float(input("Enter hourly pay rate : "))
ftax = float(input("Enter federal tax withholding rate : "))
stax = float(input("Enter state tax withholding rate : "))
income = pay*work
f = float(ftax*income)
s = float(stax*income)
Ttax = f + s

print("Employee name :",name)
print("Hours worked :",work)
print("Pay rate :",pay)
print("Gross Pay",format(income, ".2f"))
print("Deduction :\n Federal withholding :",format(f,".2f"),"\n State withholding :",format(s,".2f"),"\n Total deduction :",format(Ttax,".2f"))
print("Net Pay :",format(income - Ttax,".2f"))