class Time:
    def __init__(self, hour, minute, second):
        self.hour = hour
        self.minute = minute
        self.second = second

    def print_time(self):
        # format: hh:mm:ss
        print("{:02d}:{:02d}:{:02d}".format(self.hour, self.minute, self.second))

    def set_time(self, hour, minute, second):
        self.hour = hour
        self.minute = minute
        self.second = second
    
    def get_time(self):
        return self.hour, self.minute, self.second


time1 = Time(9, 30, 0)
time1.print_time()
time1.set_time(10, 30, 0)
time1.print_time()
print(time1.get_time())