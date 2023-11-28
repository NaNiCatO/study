import pickle
import os.path
from tkinter import filedialog
contact = {}
ans = ""

def check_exists(file):
    if os.path.isfile(file):
        raise FileExistsError
    else :
        raise FileNotFoundError


while True :
    ans = input("Enter command : ")
    if ans == "+" :
        x = input("Add Name : ")
        num = input("Number : ")
        try :
            if num.isdigit() and ("#" not in x) and ("%" not in x) and ("$" not in x):
                if x in contact.keys() :
                    print("Already exist")
                else:
                    contact.update({x : num})    
            else:
                raise KeyError
        except KeyError :
            print("Invalid Keyword")

    elif ans == "q" :
        break
    
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

    elif ans == "l" :
        filepath = filedialog.askopenfilename(filetypes=[('All Files', '*.*')], title="Load Phonebook")
        if filepath is None:
            print("\nFile not Load\n")
        else:
            file = open(filepath, "rb")
            contact = pickle.load(file)
            file.close()
            print("\nPhonebook has been loaded\n")

    elif ans == "s":
        filepath = filedialog.asksaveasfilename(filetypes=[('All Files', '*.*')], title="Save Phonebook")
        print(filepath)
        if filepath is None:
            print("\nFile not saved\n")
        else:
            try :
                check_exists(filepath)
            except FileExistsError :
                print("You can't overwrite file")

            except FileNotFoundError :
                file = open(filepath, 'wb')
                pickle.dump(contact, file)
                file.close() 
                print("\nPhonebook has been saved\n")