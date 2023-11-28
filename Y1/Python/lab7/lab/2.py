class Poly:
    def __init__(self,x):
        self.x = x

    def add(self,p):
        a = list(self.x)
        for i in range(len(self.x)):
            a[i] = a[i] + p.x[i]
        a = tuple(a)
        return Poly(a)

    def scalar_multiply(self,n):
        a = list(self.x)
        for i in range(len(self.x)):
            a[i] = a[i] * n
        a = tuple(a)
        return Poly(a)

    def multiply(self):
        pass
    
    def power(self):
        pass

    def diff(self):
        a = list(self.x)
        for i in range(len(self.x)-1):
            a[i] = a[i+1] * (i+1)
        a[len(self.x)-1] = 0
        self.x = tuple(a)
        return Poly(self.x)
    
    def integrate(self):
        a = list(self.x)
        for i in range(len(self.x),1,-1):
            a[i-1] = a[i-2] / (i-1)
        a[0] = 0
        self.x = tuple(a)
        return Poly(self.x)

    def eval(self,n):
        sum = 0
        for i in range(len(self.x)):
            if i == 0:
                sum = sum + self.x[i]
            else :
                sum = sum + self.x[i] * (n**i)
        print(sum)

    def print(self):
        result = ""
        for i in range(len(self.x)):
            if self.x[i] == 0 :
                continue
            elif i == 0 :
                result = result + str(self.x[i]) + " "
            elif self.x[i] >= 0 and i >= 1 :
                if i == 0 :
                    result = result + "+" + str(self.x[i]) + " "
                elif i == 1 :
                    result = result + "+" + str(self.x[i]) + "x" + " "
                else :
                    result = result + "+" + str(self.x[i]) + "x^" + str(i) + " "
            else :
                if i == 0 :
                    result = result + str(self.x[i]) + " "
                elif i == 1 :
                    result = result +  str(self.x[i]) + "x" + " "
                else :
                    result = result + str(self.x[i]) + "x^" + str(i) + " "
        print(result)

a = Poly((1,0,-2))
a.print()
b = a.scalar_multiply(2)
b.print()
r = a.add(b)
r.print()