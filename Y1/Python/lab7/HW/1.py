class Time :
    def __init__(self, hour, min, sec):
        self.hour = hour
        self.min = min
        self.sec = sec

    def print(self):
        self.min = self.min + (self.sec//60)
        self.sec = self.sec%60
        self.hour = self.hour + self.min//60
        self.min = self.min%60
        print(format(self.hour,"02d"),end=":")
        print(format(self.min,"02d"),end=":")
        print(format(self.sec,"02d"),end=" Hrs.")

timel = Time(9,70,70)
timel.print()