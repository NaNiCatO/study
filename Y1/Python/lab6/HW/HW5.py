def calculate(m):
    list = [1000,500,100,50,20,10,5,2,1]
    current = "notes :"
    for i in list :
        amount = m//i
        m = m%i
        if i <= 10 : current = "coins :"
        if amount == 0: 
            continue
        else :
            print(str(i)+"-Bath",current,amount)

x = int(input("Input your amount of money : "))
calculate(x)