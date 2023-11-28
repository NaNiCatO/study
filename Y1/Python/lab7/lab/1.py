class clock:
    def __init__(self,hour,min,sec):
        self.hour = hour
        self.min = min
        self.sec = sec
    
    def adjust(self):
        self.min = self.min + (self.sec//60)
        self.sec = self.sec%60
        self.hour = self.hour + self.min//60
        self.min = self.min%60

    def set_time(self,hour,min,sec):
        self.hour = hour
        self.min = min
        self.sec = sec

    def tick(self,sec):
        self.sec = self.sec + sec
    
    def get_time(self):
        self.adjust()
        if self.hour == 24:
            t = " AM"
            self.hour = 0
        elif self.hour > 12 :
            t = " PM"
            self.hour = self.hour % 12
        else :
            t = " AM"
        print(format(self.hour,"02d"),end=":")
        print(format(self.min,"02d"),end=":")
        print(format(self.sec,"02d"),end=t)
        print()

a = clock(12,30,60)
a.get_time()
a.set_time(20,35,60)
a.get_time()
a.tick(5)
a.get_time()