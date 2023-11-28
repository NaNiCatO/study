import pickle
from tkinter import filedialog
import os.path
class specialerror(Exception):
    pass


def checkfile(file):
    if os.path.exists(file):
        raise FileExistsError
    else:
        raise FileNotFoundError

def checkspecial(c):
    for i in c:
        if i in "!@#$%^&*()_+{}|:<>?~`-=[]\;',./":
            return True
       

def Phonebookmanager():
    
    dict = {}
    print('Phonebook manager')
    while True:
        c = input('enter your command: ')

        if c == 'q':
            break

        elif c == "+":
            name = input('name: ')
            num = input("phone number: ")
            try:
                    if checkspecial(name):
                        raise specialerror
                    else :
                        dict[str(name)] = num
                
            except specialerror:

                print("\ncontact has invalid keywords\n")
                

            
            
        elif c == "-":

            key = input('enter name: ')

            if key in dict.keys():

                dict.pop(str(key))

            else:
                print('name not in phonebook')
        
        elif c == "p":

             for name, number in dict.items():
                print(f"{name}: {number}")

        elif c == 'f':

            key = input("enter name: ")

            if key in dict.keys():

                print(dict[str(name)])
            else:
                print("name not in phonebook")

        elif c == 's':
            filepath = filedialog.asksaveasfilename(filetypes=[('All Files', '*.*')], title="Save Phonebook")

            if filepath is None:

                print("\nFile not saved\n")
            try:
                checkfile(filepath)
            except FileExistsError:
                
                print("\nFile already exists\n")\

            except FileNotFoundError:
                f = open(filepath, 'wb')
                pickle.dump(dict, f)
                f.close()
        
                print("\nPhonebook has been saved\n")
                

        elif c == "l" :
            filepath = filedialog.askopenfilename(filetypes=[('All Files', '*.*')], title="Load Phonebook")
            if filepath is None:
                print("\nFile not Load\n")
            else:
                file = open(filepath, "rb")
                dict = pickle.load(file)
                file.close()
                print("\nPhonebook has been loaded\n")

        else: 
            print('wrong command')
        




Phonebookmanager()