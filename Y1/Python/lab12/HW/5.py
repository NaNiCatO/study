import abc
class StationaryGood(abc.ABC): 
    @abc.abstractclassmethod
    def cost(self):
        pass

class Magazine(StationaryGood):
    def __init__(self,p,a) :
        self.price = p
        self.amount = a

    def cost(self):
        return self.price*self.amount

class Book(StationaryGood):
    def __init__(self,p,a) :
        self.price = p
        self.amount = a

    def cost(self):
        return ((self.price*90)/100)*self.amount

class Ribbon(StationaryGood):
    def __init__(self,a) :
        self.amount = a

    def cost(self):
        return self.amount*5

def getTotalCost(basket):
    sum = 0
    for i in basket :
        sum += i.cost()
    return sum

Computer_World = Magazine(70,3)
Window_7 = Book(200,2)
blue_ribbon = Ribbon(10)
basket = [Computer_World,Window_7,blue_ribbon]

print(getTotalCost(basket))
