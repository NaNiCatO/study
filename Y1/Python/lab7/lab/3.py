class LinearEquation:
    def __init__(self,a,b,c,d,e,f):
        self.__a = a
        self.__b = b
        self.__c = c
        self.__d = d
        self.__e = e
        self.__f = f

    def getA(self):
        return self.__a
    
    def getB(self):
        return self.__b

    def getC(self):
        return self.__c

    def getD(self):
        return self.__d

    def getE(self):
        return self.__e

    def getF(self):
        return self.__f

    def isSolvable(self):
        return ((self.__a*self.__d) - (self.__b*self.__c)) != 0

    def getX(self):
        up = (self.__e*self.__d) - (self.__b*self.__f)
        bot = (self.__a*self.__d) - (self.__b*self.__c)
        return up/bot
    def getY(self):
        up = (self.__a*self.__f) - (self.__e*self.__c)
        bot = (self.__a*self.__d) - (self.__b*self.__c)
        return up/bot
    
    def changeA(self,x):
        self.__a = x

    def changeB(self,x):
        self.__b = x

    def changeC(self,x):
        self.__C = x

    def changeD(self,x):
        self.__d = x

    def changeE(self,x):
        self.__e = x

    def changeF(self,x):
        self.__f = x

a = LinearEquation(3,5,2,5,7,3)
x = a.isSolvable()
print(x)
p = a.getX()
print(p)