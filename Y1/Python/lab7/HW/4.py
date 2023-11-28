from math import sqrt


class QuadraticEquation:
    def __init__(self, a, b, c):
        self.__a = a
        self.__b = b
        self.__c = c
    
    def getA(self) :
        return self.__a

    def getB(self) :
        return self.__b

    def getC(self) :
        return self.__c

    def getDiscriminant(self) :
        ans = (self.__b*self.__b) - (4*(self.__a*self.__c))
        if ans < 0:
            return 0
        else:
            return ans

    def getRoot1(self):
        c = (self.__b*self.__b) - (4*(self.__a*self.__c))
        if c < 0:
            return 0
        else:
            ans = (-self.__b + sqrt((self.__b*self.__b)-(4*self.__a*self.__c)))/(2*self.__a)
            return ans

    def getRoot2(self):
        c = (self.__b*self.__b) - (4*(self.__a*self.__c))
        if c < 0:
            return 0
        else:
            ans = (-self.__b - sqrt((self.__b*self.__b)-(4*self.__a*self.__c)))/(2*self.__a)
            return ans

a = QuadraticEquation(1,10,3)
print(a.getA())
print(a.getRoot1())
print(a.getRoot2())
print(a.getDiscriminant())