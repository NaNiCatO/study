import math
class Calculator :
    def __init__(self):
        self.acc = 0.00
    
    def set_accumulator(self,a):
        self.acc = a

    def get_accumulator(self):
        return self.acc

    def add(self,x):
        self.acc += x

    def subtract(self,x):
        self.acc -= x

    def multiply(self,x):
        self.acc *= x

    def divide(self,x):
        if x == 0:
            print("You can not divided by 0")
        else:
            self.acc /= x

    def print_result(self):
        print("Result : {:.2f}".format(self.acc))

class Sci_calc(Calculator) :
    def __init__(self):
        super().__init__()

    def square(self):
        self.acc = math.sqrt(self.acc)

    def exp(self,x):
        self.acc **= x

    def factorial(self):
        fac = 1
        for i in range(int(self.acc),0,-1):
            fac *= i
        self.acc = fac


    def print_result(self):
        print("Result : {:.2e}".format(self.acc))

cal = Calculator()

cal.set_accumulator(100)
cal.print_result()

cal.add(20)

cal.subtract(10)
cal.print_result()

cal.multiply(2)

cal.divide(5)
print(cal.get_accumulator())

sci = Sci_calc()
sci.set_accumulator(100)
sci.print_result()
sci.square()
sci.factorial()
sci.print_result()

