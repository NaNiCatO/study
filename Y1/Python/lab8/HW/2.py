def check_char(x):
    c = 0
    listchar = []
    for i in x:
        for j in listchar :
            if i == j:
                c += 1
        if c == 0 :
            listchar.append(i)
        c = 0
    return listchar

def check_frequency(x,listchar):
    listfreq = []
    c = 0
    for i in listchar:
        for j in x :
            if i == j:
                c += 1
        listfreq.append(c)
        c = 0
    return listfreq

text = str(input("Enter some text : "))
listchar = check_char(text)
listfreq = check_frequency(text,listchar)
print("-- Character Frequency Table --")
for i in range(len(listchar)):
    print("{0}\t{1:5.2f}%".format(listchar[i],(listfreq[i]/len(text))*100))
