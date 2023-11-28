class BankAccount:
    def __init__(self,bname,oname,anum,balance):
        self.bname = bname
        self.oname = oname
        self.anum = anum
        self.balance = balance
    
    def deposit(self,amount):
        if amount >= 0:
            self.balance = self.balance + amount
            print(self.balance)
        else :
            print("Can not do that")

    
    def withdraw(self,amount):
        if amount <= self.balance :
            self.balance = self.balance - amount
            print(self.balance)
        else :
            print("Can not do that")

a = BankAccount("SCB","Arm","1234323",1000)
a.deposit(500)