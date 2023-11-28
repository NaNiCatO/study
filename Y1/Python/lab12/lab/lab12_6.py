import abc

class Transportation(abc.ABC):
    
    def __init__(self,s,e,distance) :
        self.s = s
        self.e = e
        self.dis = distance
    
    @abc.abstractmethod
    def find_cost(self):
        pass



class Walk(Transportation):
    def __init__(self,s,e,distance) :
        super().__init__(s,e,distance)

    def find_cost(self):
        return 0

class Taxi(Transportation):
    def __init__(self,s,e,distance) :
        super().__init__(s,e,distance)

    def find_cost(self):
        cost = self.dis * 40
        return cost

class Train(Transportation):
    def __init__(self,s,e,distance,station) :
        super().__init__(s,e,distance)
        self.sta = station

    def find_cost(self):
        cost = self.sta * 5
        return cost



try:
    trap = Transportation("", "", 0.0)
    print(trap.find_cost())
except:
    print("This line should be printed")
    


walk = Walk("KMITL", "KMITL SCB Bank", 0.6)
taxi = Taxi("KMITL SCB Bank", "Ladkrabang Station", 5)
train = Train("Ladkrabang Station", "Payathai Station", 40, 6)
taxi2 = Taxi("Payathai Station", "The British Council", 3)
John = [walk, taxi, train, taxi2]
for travel in John:
  print(travel.find_cost())