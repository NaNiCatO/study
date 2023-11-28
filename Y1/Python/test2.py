import abc

class Sale_item(abc.ABC):
    def __init__(self,n,c):
        self.amount = n
        self.cost = c

    @abc.abstractclassmethod
    def total_cost(self):
        pass

class Appliance(Sale_item):
    def __init__(self,n,c):
        super().__init__(n,c)

    def total_cost(self):
        sum = 107*(self.cost*self.amount)/100
        return sum

class Book(Sale_item):
    def __init__(self,n,c):
        super().__init__(n,c)

    def total_cost(self):
        sum = 85*(self.cost*self.amount)/100
        return sum

class Food(Sale_item):
    def __init__(self,n,c):
        super().__init__(n,c)

    @abc.abstractclassmethod
    def total_cost(self):
        pass

class Itemized_food(Food):
    def __init__(self,n,c):
        super().__init__(n,c)

    def total_cost(self):
        sum = self.cost*self.amount
        return sum

class Measured_food(Food):
    def __init__(self,n,c):
        super().__init__(n,c)

    def total_cost(self):
        sum = self.cost*self.amount
        return sum

vegetable_oil = Itemized_food(2,40)
mango = Measured_food(1.8,70)
python_book = Book(1,200)
rice_cooker = Appliance(1,1200)
list_item = [vegetable_oil,mango,python_book,rice_cooker]
total_cost = 0
for i in list_item:
    total_cost += i.total_cost()
print(total_cost)