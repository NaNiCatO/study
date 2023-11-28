x = eval(input("Enter the number : "))
if type(x) == int :
    t = input("Displays number in bi,oc,hex or dec : ")
    if t == "bi" :
        print(format(x,"b"))
    elif t == "oc" :
        print(format(x,"o"))
    elif t == "hex" :
        print(format(x,"x"))
    elif t == "dec" :
        print(x)
else :
    t = input("Displays number in floating point(\"f\") or scientific format(\"e\") : ")
    if t == "f" :
        print(format(x,"f"))
    elif t == "e" :
        print(format(x,"e"))
