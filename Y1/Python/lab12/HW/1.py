class Clock:
    def __init__(self):
        self.h = 0
        self.m = 0
        self.s = -1

    def run(self,h = 0, m = 0, s = 0,c = False):
        while True:
            self.s += 1
            if self.s >= 60 :
                self.m += 1
                self.s = 0
            if self.m >= 60 :
                self.h += 1
                self.m = 0
            if self.h == 24 and self.s >= 0 :
                self.h = 0
            print("{0:02d}:{1:02d}:{2:02d}".format(self.h,self.m,self.s))
            if c == True and self.h == h and self.m == m and self.s == s:
                break


    def setTime(self,h,m,s):
        self.h = h
        self.m = m
        self.s = s


class AlarmClock(Clock):
    def __init__(self):
        super().__init__()
        self.alarm_hh = 0
        self.alarm_mm = 0
        self.alarm_ss = 0
        self.alarm_on_off = None

    def setAlarmTine(self,h,m,s):
        self.alarm_hh = h
        self.alarm_mm = m
        self.alarm_ss = s

    def alarm_on(self):
        self.alarm_on_off = True

    def alarm_off(self):
        self.alarm_on_off = False

    def run(self):
        self.format_time()
        if self.alarm_on_off == True:
            super().run(self.alarm_hh,self.alarm_mm,self.alarm_ss,self.alarm_on_off)
        else :
            super().run(0,0,0)
        print("Alarm!!!")
    
    def format_time(self):
        if self.alarm_hh == 24 and self.alarm_mm == 0 and self.alarm_ss == 0:
            self.alarm_hh = 0


a = AlarmClock()
a.alarm_on()
a.setAlarmTine(23,55,24)
a.run()
a.setAlarmTine(0,0,0)
a.run()