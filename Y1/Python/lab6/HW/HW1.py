def time24hourTo12hour(s):
    cut = s.split(":")
    time = "AM"
    if int(cut[0]) > 12 :
        cut[0] = int(cut[0])%12
        time = "PM"
        if cut[0] == 0 : 
            time = "AM"
    print(str(cut[0])+":"+str(cut[1]),time)

time24hourTo12hour("23:24")