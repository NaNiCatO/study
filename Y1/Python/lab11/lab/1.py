contact = {}
ans = ""
while ans != "q" :
    ans = input("Enter command : ")
    if ans == "+" :
        x = input("Add Name : ")
        num = input("Number : ")
        if num.isdigit() :
            if x in contact.keys() :
                print("Already exist")
            else:
                contact.update({x : num})    
        else:
            print("Need to be number")
         
    elif ans == "-" :
        x = input("Delete Name : ")
        try:
            del contact[x]
        except:
            print("Dose not exist")

    elif ans == "f" :
        x = input("Find Name : ")
        try:
            print(contact[x])
        except:
            print("Dose not exist")

    elif ans == "p" :
        print(contact)
    