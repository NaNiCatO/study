import os.path
file_name = input("Enter a filename : ").strip()
old = input("Enter old string: ")
new = input("Enter new string: ")


def check_exists(filepath):
    if old == new :
        raise KeyError
        
    elif os.path.isfile(filepath):
        raise FileExistsError
        
    else:
        raise FileNotFoundError


try :
    check_exists(file_name)
        
except FileNotFoundError:
    print("File is not exists")

except FileExistsError:
    file = open(file_name, "r")
    filedata = file.read()
    print(filedata)
    newfiledata = filedata.replace(old, new)

    file = open(file_name, "w")
    file.write(newfiledata)
    file.close()
    print(newfiledata)
    
except KeyError :
    print("Same Keyword")