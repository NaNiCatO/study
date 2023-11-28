addreviations = {
    "as far as I konw" : "afaik",
    "as soon as possible" : "ASAP",
    "at the moment" : "atm",
    "be right back" : "brb",
    "by the way" : "btw",
    "for your information" : "FYI",
    "in my humbke opinion" : "imho",
    "in my opinion" : "imo",
    "laughing out loud" : "lol",
    "oh my god" : "omg",
    "rolling on the floor laughing" : "rofl",
    "talk to you later" : "ttyl",
    "be" : "b",
    "because" : "cuz",
    "see" : "c",
    "the" : "da",
    "okay" : "ok",
    "are" : "r",
    "you" : "u",
    "without" : "w/o",
    "why" : "y",
    "see you" : "cu",
    "ate" : "8",
    "great" : "gr8",
    "mate" : "m8",
    "wait" : "w8",
    "later" : "l8r",
    "tomorrow" : "2mro",
    "for" : "4",
    "before" : "b4",
    "once" : "1ce",
    "and" : "&",
    "your" : "ur",
    "you're" : "ur"
}

def textese(s):
    for i in addreviations.keys():
        s = s.replace(i,addreviations.get(i))
    return s

def untextese(s):
    key_list = list(addreviations.keys())
    val_list = list(addreviations.values())
    s = s.split()
    ans = ""
    for i in range(len(val_list)):
        for j in range(len(s)) :
            if val_list[i] == s[j]:
                s[j] = key_list[i]
    
    for i in s:
        ans = ans + i + " "
    return ans
    
s = "I will be right back okay ?"

x = textese(s)
print(x)
print(untextese(x))
