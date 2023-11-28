def LCS(s1,s2):
    listword = []
    c = ""
    for i in range(len(s1)-1):
        l = i
        for j in range(len(s2)):
            if s1[l] == s2[j]:
                c = c+s1[l]
                l = l + 1
            else :
                if c != "":
                    listword.append(c)
                c = ""
                l = i 
    if listword != []:
        x = max(listword,key=len)
    else :
        x = "''"
    return x
        

print(LCS("ingenious","intelligent"))
print(LCS("philosophically","zoophilous"))
print(LCS("scada","kmitl"))
print(LCS("interactive","inaction"))
print(LCS("multiverse","metaverse"))
print(LCS("googlechrome","microsoftedge"))