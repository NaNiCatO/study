class SavingAccount :
    def __init__(self,b_name,acc_name,id,balance):
        self.bank_name = b_name
        self.acc_name = acc_name
        self.acc_id = id
        self.balance = balance
        self.transaction = []

    def deposit(self,money,person,date):
        if money >= 0 :
            self.balance += money
            self.transaction.append(["+"+str(money),person,date])
        else :
            print("Please enter positive number")

    def withdarw(self,money,person,date):
        if money >= 0 :
            if self.balance - money < 0 :
                print("You overdrawn")
            else:
                self.balance -= money
                self.transaction.append(["-"+str(money),person,date])
        else :
            print("Please enter positive number")

    def get_balance(self):
        return self.balance

    def print_statement(self):
        for i in self.transaction:
            print("money : {0}\tperson : {1}\tdate : {2}".format(i[0],i[1],i[2]))

class OverDrawnAccount(SavingAccount):
    def __init__(self,limit):
        super().__init__()
        self.overdrawn_limit = limit

    def withdarw(self,money,person,date):
        if money >= 0 :
            if self.balance - money < self.overdrawn_limit :
                print("You overdrawn your own limit")
            else:
                self.balance -= money
            self.transaction.append(["-"+str(money),person,date])


s = SavingAccount("a","b",10,1000)
s.withdarw(100,"Arm","8/12/2565")

s.print_statement()