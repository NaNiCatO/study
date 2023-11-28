import math
class Point:
    def __init__(self, x = 0, y = 0):
        self.x = x
        self.y = y
    
    def printInfo(self):
        print("Position : {}, {}".format(self.x,self.y))

class Circle(Point):
    def __init__(self,x = 0,y = 0,radius = 0):
        self.radius = radius
        super().__init__(x,y)

    def area(self):
        self.cal_area = math.pi * (self.radius ** 2)
        return self.cal_area

    def printInfo(self):
        super().printInfo()
        print("radius : {0} \narea : {1}".format(self.radius,self.cal_area))

